#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed Apr  6 11:58:13 2022

@author: page
"""

import os
import numpy as np
import math

tp={3:4.30, 4:3.18, 5:2.78, 6:2.57, 7:2.46, 8:2.37, 9:2.31, 10:2.26}
kp={1:1.960,2:1.645,3:1.901}
cc={1:3,2:math.sqrt(3),3:math.sqrt(6)}

def main():
  n=int(input('n='))
  if n<=10 and n>=3:
      t=tp[n]
      arr=input('数据(用空格隔开)：')
      num=[float(r) for r in arr.split()]
      s=np.var(np.array(num))
      ua=math.sqrt(s/n)
      A=t*ua
      
  else:
      A=0
  
  m=int(input('1正态，2均匀，3三角：'))
  k=kp[m]
  c=cc[m]
  b1=float(input('仪器允差='))
  b2=float(input('估计误差='))
  ub=math.sqrt(b1**2+b2**2)/c
  B=k*ub
  print('a=%s'%A)
  print('b=%s'%B)
  
  U=math.sqrt(A**2+B**2)
  
  return U

if __name__ == '__main__':
    i=1
    while i:
        try:
            u=main()
            print('总=%s'%u)
            i=0
        except Exception as e:
            print(e)