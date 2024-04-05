import pandas as pd
import matplotlib.pyplot as plt
import matplotlib.dates as mdates

# CSV file path
csv_file = 'bounds.csv'  # Change this to your CSV file path

# Read the CSV data into a Pandas DataFrame
df = pd.read_csv(csv_file)

# Convert the 'Timestamp' column to datetime objects
df['Timestamp'] = pd.to_datetime(df['Timestamp'])

# Plot each boundary over time
fig, ax = plt.subplots(figsize=(10, 6))

# Group by boundary to plot each separately
grouped = df.groupby('Boundary')
for name, group in grouped:
    ax.plot(group['Timestamp'], group['X'], label=f'{name} X')
    ax.plot(group['Timestamp'], group['Y'], label=f'{name} Y')

# Rotate date labels for better readability
plt.gcf().autofmt_xdate()
date_format = mdates.DateFormatter('%Y-%m-%d %H:%M:%S')
plt.gca().xaxis.set_major_formatter(date_format)

# Add legend, titles, and labels
ax.legend()
plt.title('Boundary Values Over Time')
plt.xlabel('Timestamp')
plt.ylabel('Boundary Value')

# Show plot
plt.tight_layout()
plt.show()