# -*- coding:utf-8 -*-
import math
import numpy as np
import matplotlib.pyplot as plt

def main():
  raw_data = np.loadtxt('input.csv', delimiter=',')
  raw_x = raw_data[:,0]
  raw_y = raw_data[:,1]

  result_data = np.loadtxt('out.csv', delimiter=',')
  result_x = result_data[:,0]
  result_y = result_data[:,1]

  plt.scatter(raw_x, raw_y, color='black', linestyle='solid')
  plt.scatter(result_x, result_y, color='red', linestyle='solid')
  plt.axis('scaled')
  plt.show()

if __name__ == '__main__':
  main()