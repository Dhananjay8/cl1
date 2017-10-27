import cv2
from matplotlib import pyplot as plt

src=cv2.imread("Lenna.png",cv2.IMREAD_GRAYSCALE)
plt.title("Original Image")
plt.imshow(src,cmap='gray')
plt.show()

thresh=150
maxValue=255

th,img1=cv2.threshold(src,thresh,maxValue,cv2.THRESH_BINARY)
plt.title("Fixed Threshold")
plt.imshow(img1,cmap='gray')
plt.show()

img2=cv2.adaptiveThreshold(src,maxValue,cv2.ADAPTIVE_THRESH_MEAN_C,cv2.THRESH_BINARY,5,10)
plt.title("Adaptive Threshold")
plt.imshow(img2,cmap='gray')
plt.show()

