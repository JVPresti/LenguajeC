import cv2
import os
import time

output_folder = 'caras_guardadas'
os.makedirs(output_folder, exist_ok=True)

cap = cv2.VideoCapture(0)

face_cascade = cv2.CascadeClassifier(
    cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')
eye_cascade = cv2.CascadeClassifier(
    cv2.data.haarcascades + 'haarcascade_eye.xml')

counter = 0
start_time = time.time()

while True:
    ret, frame = cap.read()

    if not ret:
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(
        gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    for (x, y, w, h) in faces:
        roi_gray = gray[y:y+h, x:x+w]
        roi_color = frame[y:y+h, x:x+w]

        eyes = eye_cascade.detectMultiScale(roi_gray)
        for (ex, ey, ew, eh) in eyes:
            eye = roi_color[ey:ey+eh, ex:ex+ew]
            # Implementa la lógica para detectar parpadeo aquí

            cv2.rectangle(roi_color, (ex, ey), (ex+ew, ey+eh), (0, 255, 0), 2)

        # Guardar la imagen de la cara detectada
        face_img = frame[y:y+h, x:x+w]
        cv2.imwrite(os.path.join(output_folder,
                    f'cara_{counter}.png'), face_img)
        counter += 1

    elapsed_time = time.time() - start_time
    fps = counter / elapsed_time if elapsed_time > 0 else 0
    cv2.putText(frame, f'Caras: {counter}', (10, 30),
                cv2.FONT_HERSHEY_SIMPLEX, 1, (0, 255, 0), 2)

    cv2.imshow('Detección de Parpadeo', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
