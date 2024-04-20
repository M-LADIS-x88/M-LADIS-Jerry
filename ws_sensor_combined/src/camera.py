import cv2
import os

camera = cv2.VideoCapture(0)

if not camera.isOpened():
    print("Error: Could not open camera.")
    exit()

image_directory = 'path/to/your/directory'
if not os.path.exists(image_directory):
    os.makedirs(image_directory)

cv2.namedWindow("Drone Camera")

print("Press spacebar to take a picture or 'q' to quit.")

i = 0

while True:
    ret, frame = camera.read()

    if not ret:
        print("Error: Can't receive frame (stream end?). Exiting.")
        break

    cv2.imshow('Drone Camera', frame)

    key = cv2.waitKey(1)

    if key == 32:  # Spacebar key
        filename = f"{image_directory}/image_{i}.jpg"
        cv2.imwrite(filename, frame)
        print(f"Image saved as {filename}")
        i += 1  

    elif key == ord('q'):  # 'q' key
        print("Exiting...")
        break

camera.release()
cv2.destroyAllWindows()