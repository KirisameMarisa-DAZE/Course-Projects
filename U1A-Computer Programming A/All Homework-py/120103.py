#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sun Sep 26 13:35:18 2021

@author: page
"""

try:
    a=int(input('a='))
    b=int(input('b='))
    c=int(input('c='))
    m=max(a,b,c)
    print('max=%s'%m)
except:print('ERROR')