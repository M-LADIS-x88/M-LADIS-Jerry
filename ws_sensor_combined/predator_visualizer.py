import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
from matplotlib.animation import FuncAnimation

# Define the path to your CSV file
csv_filename = 'predator_centroids.csv'

# Define initial setup for plot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
ax.set_title('3D Scatter Plot of Centroids and Origin')

# Function to update the plot
def update(frame):
    ax.clear()

    # Reload the CSV file data into a pandas DataFrame
    try:
        df = pd.read_csv(csv_filename)
    except FileNotFoundError:
        print(f"File '{csv_filename}' not found.")
        exit()

    # Extract X, Y, and Z data for plotting
    x = df['x']
    y = df['y']
    z = df['z']

    # Plotting
    ax.scatter(x, y, z, marker='o', s=50, c='r', alpha=0.6, label='Centroids')
    ax.scatter([0], [0], [0], marker='o', s=100, c='b', alpha=1.0, label='Origin')

    # Label the axes
    ax.set_xlabel('X Label')
    ax.set_ylabel('Y Label')
    ax.set_zlabel('Z Label')
    ax.set_title('3D Scatter Plot of Centroids and Origin')
    ax.legend()
    
    # You could also implement plotting limits for a consistent scale across updates
    # ax.set_xlim([xmin, xmax])
    # ax.set_ylim([ymin, ymax])
    # ax.set_zlim([zmin, zmax])

# Create an animation
ani = FuncAnimation(fig, update, interval=1000) # Update every 1000 milliseconds (1 second)

plt.show()