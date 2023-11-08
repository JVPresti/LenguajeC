import cv2

cap = cv2.VideoCapture(0)

face_rara = cv2.imread('C:\\Users\\nanoj\\Downloads\\lobo.png')

face_cascade = cv2.CascadeClassifier(
    cv2.data.haarcascades + 'haarcascade_frontalface_default.xml')

while True:
    ret, frame = cap.read()  # Captura los fotogramas de la cámara

    if not ret:
        break

    gray = cv2.cvtColor(frame, cv2.COLOR_BGR2GRAY)

    faces = face_cascade.detectMultiScale(
        gray, scaleFactor=1.1, minNeighbors=5, minSize=(30, 30))

    for (x, y, w, h) in faces:
        face_rara_resized = cv2.resize(face_rara, (w, h))

        frame[y:y+h, x:x+w] = face_rara_resized

    cv2.imshow('Detección de Caras con Cara Rara', frame)

    if cv2.waitKey(1) & 0xFF == ord('q'):
        break

cap.release()
cv2.destroyAllWindows()
