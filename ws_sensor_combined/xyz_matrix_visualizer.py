import pandas as pd
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D

# Load data from CSV file
csv_filename = 'xyzi_matrix.csv'
data = pd.read_csv(csv_filename)

# Extract X, Y, Z columns
x = data['X'].values
y = data['Y'].values
z = data['Z'].values

# Create a new figure and add a 3D subplot
fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

# Scatter plot
ax.scatter(x, y, z, c='r', marker='o', s = 1)

# Label the axes
ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

# Set title
ax.set_title('3D Point Cloud Visualization')

# Show the plot
plt.show()