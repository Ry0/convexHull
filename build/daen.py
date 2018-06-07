# -*- coding:utf-8 -*-
import math
import numpy as np
import matplotlib.pyplot as plt
import cv2

def createTraj(a, b, revel, resolution, rotationDeg):
  arr = []
  rotationRad = float(rotationDeg) / 180.0 * math.pi
  maxloop = int(revel*resolution)
  for i in xrange(0,maxloop):
    x = a*math.cos(float(i)/resolution)
    y = b*math.sin(float(i)/resolution)

    x = x*math.cos(rotationRad) - y*math.sin(rotationRad)
    y = x*math.sin(rotationRad) + y*math.cos(rotationRad)
    arr.append([x,y])
  return arr

def main():
  f = open('test.csv','w')
  circle1 = createTraj(2, 2, 2* math.pi, 10, 0)
  circle2 = createTraj(2, 1.8, 0.5* math.pi, 10, 20)
  circle = np.vstack((circle1, circle2))
  circleTrans = circle.transpose()


  for x in circle:
    text = str(x[0]) + "," + str(x[1]) + "\n"
    f.write(text)
  f.close()

  plt.plot(circleTrans[0], circleTrans[1] ,"o")
  plt.show()

if __name__ == '__main__':
  main()