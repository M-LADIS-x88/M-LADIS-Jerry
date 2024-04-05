

import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Replace 'centroids.csv' with the actual path to your CSV file if necessary
csv_filename = 'predator_centroids.csv'

# Load the CSV file data into a pandas DataFrame
try:
    # Assuming there are headers 'x', 'y', 'z' in the CSV
    df = pd.read_csv(csv_filename)
except FileNotFoundError:
    print(f"File '{csv_filename}' not found.")
    exit()

# Extract X, Y, and Z data for plotting
x = df['x']
y = df['y']
z = df['z']

# Plotting
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Create a scatter plot for the centroids
scatter = ax.scatter(x, y, z, marker='o', s=1, c='r', alpha=0.6, label='Centroids')

# Add a large blue dot at the origin
origin = ax.scatter([0], [0], [0], marker='o', s=100, c='b', alpha=1.0, label='Origin')

# Label the axes
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')
ax.set_title('3D Scatter Plot of Centroids and Origin')

# Show the legend
ax.legend()

# Show the plot
plt.show()