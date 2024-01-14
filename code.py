import cv2
import numpy as np
import tflite_runtime.interpreter as tflite

# Load the TFLite model and allocate tensors
model_path = '/home/pi/bjk.tflite'  # Replace with the path to your TFLite model
interpreter = tflite.Interpreter(model_path=model_path)
interpreter.allocate_tensors()

# Get input and output details
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

# Check the dimensions of the input tensor
input_shape = input_details[0]['shape']

# Find the correct camera index
camera_index = None
for i in range(10):
    cap = cv2.VideoCapture(i)
    if cap.isOpened():
        print(f"Camera index {i} is available.")
        camera_index = i
        cap.release()
    else:
        print(f"Camera index {i} is not available.")

# Check if a camera is available
if camera_index is None:
    print("Error: No camera is available.")
    exit()

# Open a connection to the USB camera
cap = cv2.VideoCapture(camera_index)

while True:
    ret, frame = cap.read()

    # Check if the frame was read successfully
    if not ret:
        print("Error: Could not read frame.")
        break

    # Preprocess the frame for the TFLite model
    resized_frame = cv2.resize(frame, (input_shape[1], input_shape[2]))
    input_frame = resized_frame.astype('float32') / 255.0
    input_frame = np.expand_dims(input_frame, axis=0)

    # Convert the input frame to UINT8
    input_frame_uint8 = (input_frame * 255).astype(np.uint8)

    # Set the input tensor
    interpreter.set_tensor(input_details[0]['index'], input_frame_uint8)

    # Run inference
    interpreter.invoke()

    # Get the detection results
    boxes = interpreter.get_tensor(output_details[0]['index'])[0]
    scores = interpreter.get_tensor(output_details[2]['index'])[0]

    # Process the detection results
    for i in range(len(boxes)):
        if scores[i] > 0.5:  # Adjust this threshold based on your needs
            ymin, xmin, ymax, xmax = boxes[i]
            h, w, _ = frame.shape
            xmin, xmax, ymin, ymax = int(xmin * w), int(xmax * w), int(ymin * h), int(ymax * h)

            # Draw bounding box on the frame
            cv2.rectangle(frame, (xmin, ymin), (xmax, ymax), (0, 255, 0), 2)

    # Display the frame
    cv2.imshow('Object Detection', frame)

    # Break the loop if 'q' key is pressed
    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

# Release the camera and close the window
cap.release()
cv2.destroyAllWindows()
