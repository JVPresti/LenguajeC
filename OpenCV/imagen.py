import numpy as np
import cv2

#Leer una imagen
img = cv2.imread('gato.jpg')

#Cambiar el espacio de color en img2
img2 = cv2.cvtColor(img, cv2.COLOR_RGB2GRAY )

#Imprimo características de la imagen en su nuevo espacio de color
# alto, ancho y canales
print("alto, alto, canales = "+ str(img2.shape))

#Muestro la imagen
cv2.imshow('Un gatito GRIS',img2)
cv2.waitKey(0)
cv2.destroyAllWindows()