from gymnasium.envs.registration import register
from gymnasium.spaces.space import Space

register(
    id="DroneExploration-v1",
    entry_point="gym_drone.envs:Drone",
    max_episode_steps=2500,
    #reward_threshold=200,
)