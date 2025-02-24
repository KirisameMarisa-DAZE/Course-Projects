#!/usr/bin/env python3
# -*- coding: utf-8 -*-
'''
Created on Wed Sep 20 20:01:34 2023

@author: page
'''

import pandas as pd
import random as rd
import numpy as np
import matplotlib.pyplot as plt

#解决matplotlib中文及负号乱码问题
from pylab import mpl
mpl.rcParams['font.sans-serif']=['SimHei']
mpl.rcParams['axes.unicode_minus']=False

#生成真随机数用
import os
import struct as st
    
class Produce(object):
    '''生成数据'''
    def __init__(self):
        '''略'''
        return
    
    def get_random_number(self):
        '''产生真随机数'''
        return st.unpack('Q', os.urandom(8))[0]
    
    def reading(self, text):
        '''从text.txt读取信息'''
        return pd.read_csv(str(text)+'.txt', sep=' ', 
                           header = None).dropna(axis=1).values#'dropna()'删除了'nan'数据
    
    def transform(self, x):
        '''改变输入x的表现形式'''
        y = [['0']*8,[0]*8]
        for i in range(8):
            for j in 0,1:#元组0,1也可写作(0,1)
                y[j][i] = x[i,j]
        return y
    
    def randomProduce(self, data, rate):
        '''根据所给概率rate选择数据集data中的某一个数据'''
        start = 0
        ran = rd.random()
        for index, scope in enumerate(rate):#元组index,scope也可写作(index,scope)
            start += scope
            if start >= ran:#在start第一次超过预先生成的[0,1)内随机数scope时，终止循环
                break#并获得对应索引index
        return data[index]
    
    def name(self):
        '''生成随机姓名'''
        #读文件
        xing_list = self.transform(self.reading('familynames'))
        ming_list = self.transform(self.reading('namecharacters'))
        #生成姓、名1、名2并返回元组
        xing_ran = self.randomProduce(xing_list[0], xing_list[1])
        ming1_ran = self.randomProduce(ming_list[0], ming_list[1])
        ming2_ran = self.randomProduce(ming_list[0], ming_list[1])
        return xing_ran, ming1_ran, ming2_ran
    
    def sex(self):
        '''随机产生性别，并global该特性'''
        global sex
        if rd.random() <= 0.5:
            sex = 0#女
        else:
            sex = 1#男
        return sex
    
    def age(self):
        '''均匀随机产生年龄，并global该特性'''
        global age 
        age = rd.randint(1, 60)
        return age
    
    def height(self):
        '''根据中国政府公开信息拟合的函数关系，正态随机生成依年龄变化的身高'''
        if sex == 0:
            if age <= 18:#未成年长身体
                ave =  -0.2937 * age ** 2 + 10.572 * age + 65.654
                if age <= 13:
                    sd = -0.0019 * age ** 4 + 0.0417 * age ** 3 - 0.2744 * age ** 2 + 1.0375 * age + 1.8097
                else:
                    sd = 5.72 
            else:#成年基本不变
                ave = 160.01 
                sd = 5.72
        else:
            if age <= 18:
                ave = -0.1931 * age ** 2 + 9.314 * age + 69.546
                sd = 0.0002 * age ** 5 - 0.0079 * age ** 4 + 0.1236 * age ** 3 - 0.7943 * age ** 2 + 2.4155 * age + 0.799
            else:
                ave = 171.42
                sd = 6.35
        h = np.random.normal(ave, sd)#生成μ,σ正态分布
        while h <= 0:#如果生成数据为负数，则重新生成
            h = np.random.normal(ave, sd)#μ,σ
        return int(h)
    
    def weight(self):
        '''根据中国政府公开信息拟合的函数关系，正态随机生成依年龄变化的体重'''
        if sex == 0:
            if age <= 18:
                ave =  -0.0024 * age ** 4 + 0.0802 * age ** 3 - 0.8124 * age ** 2 + 5.1291 * age + 4.5431
                sd =  0.0001 * age ** 5 - 0.0047 * age ** 4 + 0.0756 * age ** 3 - 0.491 * age ** 2 + 1.5753 * age - 0.2738
            else:
                ave = 51.50
                sd = 6.35
        else:
            if age <= 18:
                ave = -0.0001 * age ** 5 + 0.0023 * age ** 4 - 0.0004 * age ** 3 - 0.1431 * age ** 2 + 2.8479 * age + 7.3538
                sd = 0.00009 * age ** 5 - 0.0046 * age ** 4 + 0.0789 * age ** 3 - 0.5161 * age ** 2 + 1.6206 * age - 0.2571
            else:
                ave = 61.40
                sd = 8.45 
        m = np.random.normal(ave, sd)#μ,σ
        while m <= 0:
            m = np.random.normal(ave, sd)#μ,σ
        return int(m)

class People(object):
    '''每个人都是独一无二的'''
    def __init__(self, name, sex, age, height, weight):
        '''根据输入初始化person的属性'''
        self.name = self.name(name)#姓名
        self.sex = self.sex(sex)#性别
        self.age = age#年龄
        self.height = height#身高
        self.weight = weight#体重
        return
    
    def name(self, name):
        '''姓名'''
        self.xing = name[0]
        if rd.random() <= 0.5:
            self.ming = name[1]
        else:
            self.ming = name[1] + name[2]
        return self.xing + self.ming
    
    def sex(self, sex):
        '''性别'''
        if sex == 0:
            self.sex = '女'
        else:
            self.sex = '男'
        return self.sex

def database(amount):
    '''生成数据集'''
    database = [[0 for i in range(7)] for j in range(amount)]
    for i in range(amount):
        #if i % 100 == 0: print(i)#显示进度
        data = Produce()
        person = People(data.name(), data.sex(), data.age(), data.height(),data.weight())
        database[i] = [person.xing, person.ming, person.name, 
                       person.sex, person.age, person.height, person.weight]
    df = pd.DataFrame(database, columns = ['xing', 'ming', 'name', 
                                           'sex', 'age','height/cm','weight/kg'])
    df.index += 1#使索引从1开始
    return df

def main(amounts):
    '''主函数，数据处理与可视化'''
    #生成数据
    df = database(amounts)
    
    #简要处理数据
    ave = df.groupby('age').mean(1).dropna() #根据年龄分组，并计算每组的平均年龄
    average = [ave.index.tolist(), ave['height/cm'].values.tolist(), 
               ave['weight/kg'].values.tolist()]#[年龄，平均身高，平均体重]

    #依年龄段分组，10岁1组
    age_range = pd.cut(df['age'], [i * 10 for i in range(7)])#根据所给列表分段分组
    #依身高分组，10cm1组
    height_range = pd.cut(df['height/cm'], [i * 10 for i in range(30)])
    #依体重分组，10斤1组（5kg1组）
    weight_range = pd.cut(df['weight/kg'], [i * 5 for i in range(30)])

    #在数据集df中加入年龄范围、身高范围、体重范围列
    df['ageRange'] = age_range
    df['heightRange'] = height_range
    df['weightRange'] = weight_range
    
    #统计各年龄段的各身高体重人数，生成透视表
    '''
    h_and_w_table = pd.pivot_table(data=df,index='ageRange',columns=['heightRange', 'weightRange'],
                   values='name',aggfunc=lambda x:len(x),fill_value=0)#统计每组中姓名的个数
    height_table = pd.pivot_table(data=df,index='ageRange',columns='heightRange',
                   values='name',aggfunc=lambda x:len(x),fill_value=0)
    weight_table = pd.pivot_table(data=df,index='ageRange',columns='weightRange',
                   values='name',aggfunc=lambda x:len(x),fill_value=0)
    '''
    
    '''
    Fig.0 统计各年龄段人数并作柱形图
    '''
    '''
    plt.figure()
    counts = pd.value_counts(age_range, sort = False)
    b = plt.bar(counts.index.astype(str), counts)
    plt.bar_label(b, counts)
    plt.savefig('0.svg')
    plt.close()
    '''
    
    '''
    Fig.1 统计各姓氏频率并作柱形图
    '''
    plt.figure()
    #实际频率
    counts = pd.value_counts(df['xing']) / amounts
    ax1 = plt.bar(counts.index.astype(str), counts, label='实际')
    plt.ylim([0, 0.4]);
    # 在左侧显示图例
    plt.legend(loc="upper left")
    # 设置标题
    plt.title("Fig.1 姓氏")
    # 为两条坐标轴设置名称
    plt.xlabel('姓氏')
    plt.ylabel('实际')
    plt.bar_label(ax1, counts)
    
    #理论概率
    data = Produce()
    p = data.transform(data.reading('familynames'))
    ax2 = plt.twinx()
    ax2.set_ylabel('理论')
    # 设置坐标轴范围
    ax2.set_ylim([0, 0.4]);
    plt.plot(counts.index.astype(str), p[1], 'r', marker='.', c='r', ms=5, linewidth='1', label='理论')
    ax2.legend(loc="upper right")
    #显示y坐标
    for a, b in zip(counts.index.astype(str), p[1]):
        plt.text(a, b, b, ha='center', va='bottom', fontsize=8)
    
    #保存
    #plt.savefig('1.svg')
    plt.savefig('PB21051049_homework1_1.jpg')
    plt.close()
    
    '''
    Fig.2 统计各年龄平均身高并作散点图
    '''
    plt.figure()
    #实际均值
    x = average[0]
    y = average[1]
    plt.style.use('seaborn')
    plt.scatter(x, y, s=30, label='Real')#s为点大小
    plt.legend(loc="upper left")
    plt.ylim([0, 200]);
    plt.title("Fig.2 Height")
    plt.xlabel('Age')
    plt.ylabel('Real')

    #理论曲线
    age = np.linspace(1, 18, 100)
    ave1 =  0.5 * (-0.2937 * age ** 2 + 10.572 * age + 65.654 
                  -0.1931 * age ** 2 + 9.314 * age + 69.546)
    age2 = np.linspace(18, 60, 100)
    ave2 = 0.5 * (160.01 + 171.42) + 0 * age2
    ax = plt.twinx()
    ax.set_ylim([0, 200]);
    ax.set_ylabel('Ideal')
    # 调用Axes对象的绘图接口，映射数据
    ax.plot(age, ave1, color = 'g', label='Ideal (0-18)')
    ax.plot(age2, ave2, color = 'r', label='Ideal (18-60)')
    ax.legend(loc="upper right")
    
    #保存
    #plt.savefig('2.svg')
    plt.savefig('PB21051049_homework1_2.jpg')
    plt.close()
    
    '''
    Fig.3 统计各年龄平均体重并作散点图
    '''
    #实际均值
    plt.figure()
    x = average[0]
    y = average[2]
    plt.style.use('seaborn')
    plt.scatter(x, y, s=30, label='Real')#s为点大小
    plt.legend(loc="upper left")
    plt.ylim([0, 100]);
    plt.title("Fig.3 Weight")
    plt.xlabel('Age')
    plt.ylabel('Real')
    #理论曲线
    age = np.linspace(1, 18, 100)
    ave1 =  0.5 * (-0.0024 * age ** 4 + 0.0802 * age ** 3 - 0.8124 * age ** 2 + 5.1291 * age + 4.5431 
                  -0.0001 * age ** 5 + 0.0023 * age ** 4 - 0.0004 * age ** 3 - 0.1431 * age ** 2 + 2.8479 * age + 7.3538)
    age2 = np.linspace(18, 60, 100)
    ave2 = 0.5 * (51.50 + 61.40) + 0 * age2
    ax = plt.twinx()
    ax.set_ylim([0, 100]);
    ax.set_ylabel('Ideal')
    # 调用Axes对象的绘图接口，映射数据
    ax.plot(age, ave1, color = 'g', label='Ideal (0-18)')
    ax.plot(age2, ave2, color = 'r', label='Ideal (18-60)')
    ax.legend(loc="upper right")
    
    #保存
    #plt.savefig('3.svg')
    plt.savefig('PB21051049_homework1_3.jpg')
    plt.close()
    
    '''
    保存
    '''
    df[['name', 'age', 'height/cm', 'weight/kg']].to_csv('PB21051049_homework1.out.csv')
    '''
    df.to_csv('--people.csv')
    df[['name', 'age', 'height/cm', 'weight/kg']].to_csv('--person.csv')
    df[['name', 'age', 'height/cm', 'weight/kg']].to_csv('--person.txt', sep=' ')
    h_and_w_table.to_csv('-h&w_table.csv')
    height_table.to_csv('-h_table.csv')
    weight_table.to_csv('-w_table.csv')
    '''
    return

if __name__ == '__main__':
    main(200)
