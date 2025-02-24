#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Sat Sep 25 14:47:14 2021

@author: page
"""

from time import sleep
from sys import exit
from subprocess import call

i = 0

def Login():
    global v,i#v为VIP等级（0～4依次降低）, i为密码输入错误次数
    us=str(input('Username:'))
    ps=str(input('Password:'))
    if (us,ps)==('',''):
        v=0#admin
        print('\nWelcome,  administrator!')
    elif (us,ps)==('username','password'):
        v=1#SVIP
        print('\nSVIP!')
    elif (us,ps)==('Username','Password'):
        v=2#VIP
        print('\nVIP')
    elif (us,ps)==('us','ps'):
        v=3#usual user
        print('\nLogin succeed.')
    else:
        if i == 0:
            v=4#None user
            print('\nAccess Prohibited!\nPlease check your inputs.')
        elif i>=1 and i<=2:
            v=4#None user
            print('\nAccess Prohibited!\nPlease cheak your inputs.')
            lefti=3-i
            print('['+str(lefti)+' time(s) left!]')
        else:
            v=5#Bad user
            print('\nAccess Prohibited!')
            print('You have intputed FALSE Username or FALSE Password for 4 times.\nNow we will jump to another page.\nThen the app will closed later.')
            sleep(10) 
            
    proceeding()
    
    return v

def proceeding():
    global rs,i
    if v==0:
        print('正在启动程序……')
        print('tips: 在任意输入框内输入0(课次除外，0表示学期大作业)，即可退出程序！')
        print('tips: 在任意输入框内不输入，即可跳过此步骤！')
        code = choose()
        
        e=str(a);g=str(c);h=str(d)
        if b == 1: f = '暑'
        elif b == 2: f = '秋'
        elif b == 3: f = '寒'
        else: f = '春'
        
        if code == '':
            print('【以下步骤仅作展示，不执行任何代码】')
            print('\n接下来为您查找202'+e+'年'+f+'季学期第'+g+'次作业的第'+h+'题，索引号为%s'%code)
            print('Success!')
            str(input('请选择您想要打开的文件： [py] / c '))
            print('启动中，请稍后……')
            print('【展示环节到此结束】')
            pys0='无'
            pys1='无'
        
        else:
        
            print('\n接下来为您查找202'+e+'年'+f+'季学期第'+g+'次作业的第'+h+'题，索引号为%s'%code)
            print('Success!')
            
            rs=str(input('请选择您想要打开的文件： [py] / c '))
            print('启动中，请稍后……')
            
            pys0=str('chmod u+x /Users/page/Documents/4-app/Homework/All\ Homework-py/'+str(code)+'.py\n')
            pys1=str('/Users/page/Documents/4-app/Homework/All Homework-py/'+str(code)+'.py\n')

            cs0=str('chmod u+x /Users/page/Documents/-文稿/1-学习/1-理学/5-计算机科学/2-C/Homework/All_Homework_c/'+str(code)+'\n')
            cs1=str('cd /Users/page/Documents/-文稿/1-学习/1-理学/5-计算机科学/2-C/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'\n')
            cs2=str('gcc -Wall -g -o main main.c\n')
            cs3=str('/Users/page/Documents/-文稿/1-学习/1-理学/5-计算机科学/2-C/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'/main\n')
            
            if rs == '':call(pys0+pys1,shell = True)
            else:call(cs0+cs1+cs2+cs3,shell = True)
            
        res=str(input('显示源码？\n [y] / n '))
        if res == '':print('索引地址为：%s\n请自行查找！'%pys1)
        else:pass
        ano=str(input('Another file?\n [y] / n '))
        if ano == '':restart()
        else:
            print('After 5 sec, this appication will close automatically.')
            sleep(5)
            exit()
        

    elif v==1:
        print('正在启动程序……')
        print('tips: 在任意输入框内输入0(课次除外，0表示学期大作业)，即可退出程序！')
        sleep(1)
        
        code = choose()
        
        e=str(a);g=str(c);h=str(d)
        if b == 1: f = '暑'
        elif b == 2: f = '秋'
        elif b == 3: f = '寒'
        else: f = '春'
        
        print('\n接下来为您查找202'+e+'年'+f+'季学期第'+g+'次作业的第'+h+'题，索引号为%s'%code)
        print('查找中，请稍后……')
        sleep(1)
        print('Success!')
        
        rs=str(input('请选择您想要打开的文件： [.py] / .c\n（默认选.py，回车即可；若想更改，请输入任意非空字符）'))
        print('启动中，请稍后……')
        
        pys0=str('chmod u+x /Users/page/Documents/4-app/Homework/All\ Homework-py/'+str(code)+'.py\n')
        pys1=str('/Users/page/Documents/4-app/Homework/All Homework-py/'+str(code)+'.py\n')
        
        print(pys0+pys1)
        
        cs0=str('chmod u+x /Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'\n')
        cs1=str('cd /Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'\n')
        cs2=str('gcc -Wall -g -o main main.c\n')
        cs3=str('/Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'/main\n')
        
        if rs == '':call(pys0+pys1,shell=True)
        else:
            call(cs0+cs1+cs2+cs3,shell=True)
        
    elif v==2:
        print('正在启动程序……')
        print('tips: 在任意输入框内输入0(课次除外，0表示学期大作业)，即可退出程序！')
        sleep(1)
        print('tips: 嫌速度慢？开通SVIP即可再提升1倍启动速度！')
        sleep(1)
        
        code = choose()
        
        e=str(a);g=str(c);h=str(d)
        if b == 1: f = '暑'
        elif b == 2: f = '秋'
        elif b == 3: f = '寒'
        else: f = '春'
        
        print('\n接下来为您查找202'+e+'年'+f+'季学期第'+g+'次作业的第'+h+'题，索引号为%s'%code)
        print('查找中，请稍后……')
        sleep(1)
        print('tips: 嫌速度慢？开通SVIP即可再提升1倍查询速度！')
        sleep(1)
        print('Success!')
        
        rs=str(input('请选择您想要打开的文件： [.py] / .c\n（默认选.py，回车即可；若想更改，请输入任意非空字符）'))
        print('启动中，请稍后……')
        pys=str('/Users/page/Documents/4-app/Homework/All Homework-py/'+str(code)+'.py')
        
        cs0=str('chmod u+x /Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'\n')
        cs1=str('cd /Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'\n')
        cs2=str('gcc -Wall -g -o main main.c\n')
        cs3=str('/Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'/main\n')
        
        if rs == '':call(pys)
        else:
            call(cs0+cs1+cs2+cs3,shell=True)
        
    elif v==3:
        print('正在启动程序……')
        sleep(5)
        print('tips: 在任意输入框内输入0(课次除外，0表示学期大作业)，即可退出程序！')
        sleep(5)
        print('tips: 嫌速度慢？开通VIP即可提升10倍启动速度与5倍关闭速度！')
        sleep(10)
        
        code = choose()
        
        e=str(a);g=str(c);h=str(d)
        if b == 1: f = '暑'
        elif b == 2: f = '秋'
        elif b == 3: f = '寒'
        else: f = '春'
        
        print('\n接下来为您查找202'+e+'年'+f+'季学期第'+g+'次作业的第'+h+'题，索引号为%s'%code)
        sleep(1)
        print('查找中，请稍后……')
        sleep(6)
        print('tips: 嫌速度慢？开通VIP即可提升10倍查询速度！')
        sleep(3)
        print('Loading...')
        sleep(10)
        print('Success!')
        
        rs=str(input('请选择您想要打开的文件： [.py] / .c\n（默认选.py，回车即可；若想更改，请输入任意非空字符）'))
        print('启动中，请稍后……')
        pys=str('/Users/page/Documents/4-app/Homework/All Homework-py/'+str(code)+'.py')
        
        cs0=str('chmod u+x /Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'\n')
        cs1=str('cd /Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'\n')
        cs2=str('gcc -Wall -g -o main main.c\n')
        cs3=str('/Users/page/Documents/4-app/Homework/All_Homework_c/'+str(code)+'/'+str(code)+'/main\n')
        
        if rs == '':call(pys)
        else:
            call(cs0+cs1+cs2+cs3,shell=True)
        
    elif v==4:
        print('After 5 sec, this appication will restart automatically.')
        i += 1
        sleep(5)
        Login()
        
    else:
        print('404 NOT FOUND')
        sleep(1)
        print('Please wait for a while...')
        sleep(5)
        print('WRONG.\nAfter 5 sec, this appication will close automatically.')
        sleep(1)
        print('Now begin to close down...')
        sleep(1)
        print('Good Bye...')
        sleep(1)
        print('Good Luck...')
        sleep(1)
        print('BYE.')
        sleep(1)
        exit()

def choose():
    '用户选择想查看的题目并返回一个索引号'
    global a,b,c,d
    
    #年
    while True:
        try:
            a=str(input('年(2021~2025):'))
            if v == 0 and a=='':break
            else:pass
            a=int(a)-2020
        except:
            a=-1
            print('Please enter a int number!')
        if a>=1 and a<=5:break
        elif a == -2020: 
            print('正在关闭程序，请稍后……')
            if v==0:pass
            elif v==1 or v==2:sleep(1)
            else:sleep(5)
            exit()
        else:print('Please enter a true number!')
    
    #学期
    if a == 1: 
        b = 2
        print('\n学期(1-暑,2-秋,3-寒,4-春):2')
    elif a == 5:
        while True:
            try:
                b=str(input('学期(3-寒,4-春):'))
                if v == 0 and b=='':break
                else:pass
                b=int(b)
            except:
                b=-1
                print('Please enter a int number!')
            if b>=3 and b<=4:break
            elif b == 0: 
                print('正在关闭程序，请稍后……')
                if v==0:pass
                elif v==1 or v==2:sleep(1)
                else:sleep(5)
                exit()
            else:print('Please enter a true number!')    
    else:
        while True:
            try:
                b=str(input('学期(1-暑,2-秋,3-寒,4-春):'))
                if v == 0 and b=='':break
                else:pass
                b=int(b)
            except:
                b=-1
                print('Please enter a int number!')
            if b>=1 and b<=4:break
            elif b == 0: 
                print('正在关闭程序，请稍后……')
                if v==0:pass
                elif v==1 or v==2:sleep(1)
                else:sleep(5)
                exit()
            else:print('Please enter a true number!')
    
    #课次
    while True:
        try:
            c=str(input('课次(1~18):'))
            if v == 0 and b=='':break
            else:pass
            c=int(c)
        except:
            c=-1
            print('Please enter a int number!')
        if c<=18 and c>=0:break
        else:print('Please enter a true number!')
    
    #题号
    while True:
        try:
            d=str(input('题号(1~99):'))
            if v == 0 and b=='':break
            else:pass
            d=int(d)
        except:
            d=-1
            print('Please enter a int number!')
        if d>=1 and d<=99:break
        elif d == 0: 
            print('正在关闭程序，请稍后……')
            if v==0:pass
            elif v==1 or v==2:sleep(1)
            else:sleep(5)
            exit()
        else:print('Please enter a true number!')
      
    code = 100000*a+10000*b+100*c+d
    
    return code  #返回一个索引号

def restart():
    proceeding()

def main():
    Login()
    
if __name__ == '__main__':
    main()