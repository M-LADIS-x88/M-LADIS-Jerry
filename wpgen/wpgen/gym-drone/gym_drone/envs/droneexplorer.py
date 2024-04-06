__credits__ = ["Andrea PIERRÉ"]

import math
import warnings
from typing import TYPE_CHECKING, Optional

import numpy as np
from datetime import datetime
import pandas as pd

import random

import gymnasium as gym
from gymnasium import error, spaces
from gym.error import DependencyNotInstalled
from gym.utils import EzPickle, colorize
from gym.utils.step_api_compatibility import step_api_compatibility
import time

from ml_lofi.sim.lofi_sim_external_control import update_state, poster_generator, calculate_distance


FPS = 1
W = 25.095 / 2
H = 37.389 / 2

START_X = 0
START_Y = 0
START_YAW = 0
START_PX = random.uniform(0.8 * W, W) * random.choice([-1, 1])
START_PY = random.uniform(0.8 * H, H) * random.choice([-1, 1])

class Drone(gym.Env, EzPickle):

    metadata = {
        "render_modes": ["human", "rgb_array"],
        "render_fps": FPS,
    }

    def __init__(
        self,
        render_mode: Optional[str] = None,
    ):
        EzPickle.__init__(
            self,
            render_mode,
        )

        self.prev_reward = None

        # useful range is -1 .. +1, but spikes can be higher
        #self.observation_space = spaces.Box(low, high)

        self.observation_space = spaces.Dict({'position': spaces.Box(low=-1, high=+1, shape=(2,), dtype=np.float32),
                                              'enemy_position': spaces.Box(low=-1, high=+1, shape=(2,), dtype=np.float32),
                                              'nearest_poster': spaces.Box(low=-1, high=+1, shape=(2,), dtype=np.float32),
                                              'poster_centroid': spaces.Box(low=-1, high=+1, shape=(2,), dtype=np.float32),
                                              })

        self.action_space = spaces.Box(-0.95, +0.95, (2,), dtype=np.float32)

        self.render_mode = render_mode


    def reset(
        self,
        *,
        seed: Optional[int] = None,
        options: Optional[dict] = None,
    ):
        super().reset(seed=seed)
        self.game_over = False
        self.prev_shaping = None

        self.drone_coverage_radius = 1.16

        self.data = []
        self.waypoint = Waypoint(0,0)
        self.checked_posters = 0

        self.t0 = time.time()
        self.t = 0
        self.ti = 0
        self.drone_x = START_X
        self.drone_y = START_Y
        self.drone_yaw = START_YAW
        self.predator_x = START_PX
        self.predator_y = START_PY
        self.vx = 0
        self.vy = 0
        self.pcd = None
        self.time_to_update_LiDAR = 0
        self.lidar_coverage_radius = 5.70275
        self.posters = poster_generator()
        self.z_max = 6.096

        if self.render_mode == "human":
            self.render()
        return self.step(np.array([0, 0]))[0], {}

    def step(self, action):
        action = np.clip(action, -0.95, +0.95).astype(np.float32)
        self.waypoint = Waypoint(self.unnormalize(float(action[0]), float(action[1]))[0], self.unnormalize(float(action[0]), float(action[1]))[1])
        waypoint_dist = calculate_distance(self.drone_x, self.drone_y, self.waypoint.x, self.waypoint.y)[2]

        # Find nearest poster location and distance from it
        nearest_poster_dist = math.sqrt(W**2 + H**2)
        nearest_poster_coord = [0, 0]
        for poster in self.posters:
            if not poster.isChecked:
                poster_dist = calculate_distance(self.drone_x, self.drone_y, poster.x, poster.y)[2]
                if poster_dist < nearest_poster_dist:
                    nearest_poster_dist = poster_dist
                    nearest_poster_coord = [poster.x, poster.y]

        #print("NEW WAYPOINT", self.waypoint.x, self.waypoint.y, self.t)
        while abs(waypoint_dist) > abs(self.drone_coverage_radius):
            postersX = []
            postersY = []
            postersChecked = []

            for poster in self.posters:
                postersX.append(poster.x)
                postersY.append(poster.y)
                postersChecked.append(poster.isChecked)

            self.data.append(
            [
                self.t,
                self.drone_x,
                self.drone_y,
                self.drone_yaw,
                self.vx,
                self.vy,
                self.waypoint.x,
                self.waypoint.y,
                self.predator_x,
                self.predator_y,
                0,
                "null",
                2 * W,
                2 * H,
                postersX,
                postersY,
                postersChecked,
            ])
            (
                self.t,
                self.ti,
                self.drone_x,
                self.drone_y,
                self.drone_yaw,
                self.predator_x,
                self.predator_y,
                self.predator_dist,
                self.vx,
                self.vy,
                self.pcd,
                self.time_to_update_LiDAR,
            ) = update_state(
                self.t0,
                self.t,
                self.ti,
                self.drone_x,
                self.drone_y,
                self.drone_yaw,
                self.predator_x,
                self.predator_y,
                self.vx,
                self.vy,
                self.pcd,
                self.time_to_update_LiDAR,
                self.lidar_coverage_radius,
                self.posters,
                self.z_max,
                self.waypoint,
                None,
                None,
            )
            waypoint_dist = calculate_distance(self.drone_x, self.drone_y, self.waypoint.x, self.waypoint.y)[2]
            if (self.predator_dist <= 2 * self.drone_coverage_radius + 0.5):
                self.game_over = True
                #print("CRASH", self.predator_dist, self.t)
            for poster in self.posters:
                if not poster.isChecked:
                    current_poster_dist = calculate_distance(self.drone_x, self.drone_y, poster.x, poster.y)[2]
                    if current_poster_dist < 2 * self.drone_coverage_radius + 0.5:
                        poster.isChecked = True
                        self.checked_posters += 1
            #print(self.drone_x, self.drone_y, self.waypoint.x, self.waypoint.y, self.vx, self.vy, self.t)


        state = dict(
            position=np.array(self.normalize(self.drone_x, self.drone_y), dtype=np.float32),
            enemy_position=np.array(self.normalize(self.predator_x, self.predator_y), dtype=np.float32),
            nearest_poster=np.array(self.normalize(nearest_poster_coord[0], nearest_poster_coord[1]), dtype=np.float32),
            poster_centroid=np.array(self.normalize(self.centroid(self.posters)[0], self.centroid(self.posters)[1]), dtype=np.float32),
        )

        #print(state['position'], state['nearest_poster'])

        reward = 0

        shaping = (
            - 20 * (-np.tanh(calculate_distance(state['position'][0], state['position'][1], state['enemy_position'][0], state['enemy_position'][1])[2]) + 1) # avoid enemy
            + 10 * (-np.tanh(calculate_distance(state['position'][0], state['position'][1], state['nearest_poster'][0], state['nearest_poster'][1])[2]) + 1) # approach posters
            - 2.5 * (-np.tanh(calculate_distance(state['position'][0], state['position'][1], state['poster_centroid'][0], state['poster_centroid'][1])[2]) + 1) # avoid checked posters
        )
    
        if self.prev_shaping is not None:
            reward = shaping - self.prev_shaping
        self.prev_shaping = shaping

        terminated = False
        if self.game_over:
            terminated = True

        if self.render_mode == "human":
            self.render()
        return state, reward, terminated, False, {}

    def render(self):
        if self.render_mode is None:
            gym.logger.warn(
                "You are calling render method without specifying any render mode. "
                "You can specify the render_mode at initialization, "
                f'e.g. gym("{self.spec.id}", render_mode="rgb_array")'
            )
            return
        return

    def close(self):
        timestamp = datetime.now().strftime("%Y-%m-%d_%H-%M-%S")
        timestamp = "0"
        csv_filename = f"flight_logs/drone_movement_{timestamp}.csv"
        df_with_duplicates = pd.DataFrame(
            self.data,
            columns=[
                "Time (s)",
                "X",
                "Y",
                "Yaw",
                "VX",
                "VY",
                "wX",
                "wY",
                "Predator X",
                "Predator Y",
                "# Posters Detected",
                "Poster in Position",
                "Arena Width (m)",
                "Arena Length (m)",
                "Posters X",
                "Posters Y",
                "Posters Checked",
            ],
        )
        is_duplicate_time = df_with_duplicates["Time (s)"].duplicated(keep="first")
        df = df_with_duplicates[~is_duplicate_time]
        df_with_duplicates.to_csv(csv_filename, index=False)
        return
    
    
    # -=-=- Helper functions -=-=- #

    def normalize(self, x, y):
        nx = x/W
        ny = y/H
        return nx, ny
    
    def unnormalize(self, nx, ny):
        x = W*nx
        y = H*ny
        return x, y
    
    def centroid(self, posters):
        sum_x = 0
        sum_y = 0
        sum_posters = 0
        centroid_x = 0
        centroid_y = 0
        for poster in posters:
            if poster.isChecked:
                sum_x += poster.x
                sum_y += poster.y
                sum_posters += 1
        if sum_posters != 0:
            centroid_x = sum_x / sum_posters
            centroid_y = sum_y / sum_posters
        return [centroid_x, centroid_y]


class Waypoint:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y