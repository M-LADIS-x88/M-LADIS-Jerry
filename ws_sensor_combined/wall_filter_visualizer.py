import pandas as pd
import matplotlib.pyplot as plt
from matplotlib.patches import Patch

# Replace 'z.csv' with the actual path to your CSV file if necessary
csv_filename = 'z.csv'

# Load the CSV file data into a pandas DataFrame
try:
    df = pd.read_csv(csv_filename)
except FileNotFoundError:
    print(f"File '{csv_filename}' not found.")
    exit()

# Extract X, Y, and Z data for plotting
x = df['x']
y = df['y']
z = df['z']

# Define colors based on Z values
colors = ['blue' if value > 2.75 else 'red' for value in z]

# Plotting in the XY plane using the specified colors
plt.scatter(x, y, color=colors, alpha=0.6, s=100)

# Create legend patches
pillar_patch = Patch(color='blue', label='Pillar')
poster_patch = Patch(color='red', label='Poster')

# Add the custom legend outside the plot area in the middle
#plt.legend(handles=[pillar_patch, poster_patch], loc='center', bbox_to_anchor=(0.5, 0.5))

font_size = 12  # Adjust as necessary

# Add the custom legend with a larger font size
plt.legend(handles=[pillar_patch, poster_patch], loc='upper center', bbox_to_anchor=(0.5, 0.5), fontsize=font_size)

# Set limits for the x-axis and y-axis
plt.xlim(-20, 20)
plt.ylim(-20, 20)

# Label the axes with a larger font size
plt.xlabel('X Label', fontsize=font_size)
plt.ylabel('Y Label', fontsize=font_size)
plt.title('2Pillars and Posters', fontsize=font_size + 2)

# Add the grid to the plot
plt.grid(True)

# Increase the tick label font size
plt.tick_params(axis='both', which='major', labelsize=font_size)

# Show the plot
plt.show()