import cv2
import numpy as np

image = cv2.imread("/Users/matvey/PyCharmMiscProject/66666.jpg")

cv2.imshow("original", image)
cv2.waitKey(0)

blurred_image = cv2.GaussianBlur(image, (11, 11), 0)
cv2.imshow("blurred", blurred_image)
cv2.waitKey(0)

hsv_image = cv2.cvtColor(blurred_image, cv2.COLOR_BGR2HSV)
cv2.imshow("hsv", hsv_image)
cv2.waitKey(0)

hsv_min = np.array((36, 25, 25), np.uint8)
hsv_max = np.array((70, 255, 255), np.uint8)
green_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)
cv2.imshow("mask_green", green_mask)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(green_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for i in contours:
    if cv2.contourArea(i) < 100:
        continue
    x, y, w, h = cv2.boundingRect(i)
    cx, cy = int(x + w / 2), int(y + h / 2)
    cv2.rectangle(image, (x, y), (x + w, y + h), (255, 0, 0), 2)
    cv2.circle(image, (cx, cy), 9, (0, 0, 255), 3)

hsv_min = np.array((20, 100, 100), np.uint8)
hsv_max = np.array((36, 255, 255), np.uint8)
yellow_mask = cv2.inRange(hsv_image, hsv_min, hsv_max)
cv2.imshow("mask_yellow", yellow_mask)
cv2.waitKey(0)

contours, hierarchy = cv2.findContours(yellow_mask.copy(), cv2.RETR_TREE, cv2.CHAIN_APPROX_SIMPLE)
for i in contours:
    if cv2.contourArea(i) < 100:
        continue
    x, y, w, h = cv2.boundingRect(i)
    cx, cy = int(x + w / 2), int(y + h / 2)
    cv2.rectangle(image, (x, y), (x + w, y + h), (0, 255, 0), 2)
    cv2.circle(image, (cx, cy), 9, (0, 0, 255), 3)

cv2.imshow('result', image)
cv2.waitKey(0)
cv2.destroyAllWindows()