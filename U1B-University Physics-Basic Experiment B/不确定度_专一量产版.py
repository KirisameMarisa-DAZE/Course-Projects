#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Wed May 11 23:28:36 2022

@author: page
"""

import os
import numpy as np
import math

tp={3:4.30, 4:3.18, 5:2.78, 6:2.57, 7:2.46, 8:2.37, 9:2.31, 10:2.26}
kp={1:1.960,2:1.645,3:1.901}
cc={1:3,2:math.sqrt(3),3:math.sqrt(6)}

def main():
  n=3
  if n<=10 and n>=3:
      t=tp[n]
      arr=input('数据(用空格隔开)：')
      num=[float(r) for r in arr.split()]
      s=np.var(np.array(num))
      ua=math.sqrt(s/n)
      A=t*ua
  else:
      A=0
  
  m=2
  k=kp[m]
  c=cc[m]
  b1=0.0166666666666666666666666666667
  b2=0.0166666666666666666666666666666667
  ub=math.sqrt(b1**2+b2**2)/c
  B=k*ub
  
  U=math.sqrt(A**2+B**2)
  
  return U

if __name__ == '__main__':
    i=1
    while i:
        try:
            u=main()
            print(u)

            
        except Exception as e:
            print(e)