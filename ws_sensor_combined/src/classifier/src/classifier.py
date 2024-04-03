import os
from PIL import Image, ImageOps
import numpy as np
import matplotlib.pyplot as plt
import tensorflow as tf
from tensorflow.keras.models import load_model

folder_path = os.path.join('src', 'classifier', 'src', 'test_images')

class_names = []
with open(os.path.join('src', 'classifier', 'src', "class_names.txt"), "r") as file:
    class_names = [line.strip() for line in file.readlines()]

image_arrays = []
target_size = (256, 256)

for filename in os.listdir(folder_path):
    if filename == ".DS_Store":
        continue
    image_path = os.path.join(folder_path, filename)
    img = Image.open(image_path)
    #img = ImageOps.flip(img)   //if needed, uncomment this line
    img_resized = img.resize(target_size)
    img_array = np.array(img_resized)
    if img_array.shape == target_size + (3,):
        image_arrays.append(img_array)
    else:
        print(f"Ignoring {filename} due to inconsistent dimensions.")

test_images = np.array(image_arrays)
model = load_model(os.path.join('src', 'classifier', 'src','models', 'Big_Ten.h5'))
test_loss, test_acc = model.evaluate(test_images, verbose=2)

probability_model = tf.keras.Sequential([model, tf.keras.layers.Softmax()])
predictions = probability_model.predict(test_images)

i = 0
for p in predictions:
    predicted_label = class_names[np.argmax(p)]
    certainty = 100.0 * np.max(p)
    certainty = round(certainty, 2)
    print("We believe Poster " + str(i) + " is " + str(predicted_label) + " with " + str(certainty) + "% certainty")
    with open("classification_results.txt", "a") as file:
        file.write("We believe Poster " + str(i) + " is " + str(predicted_label) + " with " + str(certainty) + "% certainty\n")
    i = i + 1      

def plot_image(i, predictions_array, img):
    img = img[i]
    plt.grid(False)
    plt.xticks([])
    plt.yticks([])

    plt.imshow(img, cmap=plt.cm.binary)

    predicted_label = np.argmax(predictions_array)

    plt.xlabel("{} {:2.0f}% ({})".format(class_names[predicted_label], 
                                          100.0 * np.max(predictions_array), 
                                          class_names[np.argmax(predictions_array)]))

def plot_value_array(i, predictions_array):
    plt.grid(False)
    plt.xticks(range(14))
    plt.yticks([])
    thisplot = plt.bar(range(14), predictions_array, color="#777777")
    plt.ylim([0, 1])
    predicted_label = np.argmax(predictions_array)
'''
num_rows = 3
num_cols = 5
num_images = num_rows * num_cols
plt.figure(figsize=(2 * 2 * num_cols, 2 * num_rows))
for i in range(num_images):
    plt.subplot(num_rows, 2 * num_cols, 2 * i + 1)
    plot_image(i, predictions[i], test_images)
    plt.subplot(num_rows, 2 * num_cols, 2 * i + 2)
    plot_value_array(i, predictions[i])

plt.tight_layout()
plt.show()
'''
