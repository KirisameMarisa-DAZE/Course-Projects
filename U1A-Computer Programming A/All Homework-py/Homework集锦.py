#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 25 13:28:35 2021

@author: page
"""

class Task():
    def __main__(self):return
    
    def task1():print('Hello World!')
        
    def task2():print('*\n***\n*****\n*******\n*****\n***\n*')
        
    def task3():
        try:
            a=input('a=')
            b=input('b=')
            c=input('c=')
            m=max(a,b,c)
            print('max=%s'%m)
        except Exception() as e:print('Error:%s'%e)
            
    def task4():
        f=float(input("F="))
        c=5/9*(f-32)
        print('C=%s'%c)
        
def choose(x):
    try:
        if x==1:
            Task.task1()
        elif x==2:
            Task.task2()
        elif x==3:
            Task.task3()
        elif x==4:
            Task.task4()
        else:print('Please enter a true number!')
    except Exception() as e:print('Error:%s'%e)

        
def main():
    while True:
        try:l=int(input('Please choose which task(1~4) you want to see(input 0 to quit):'))
        except:l=0.1
        if l == 0:break
        else:choose(l)
    
if __name__ == '__main__':main()