#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Mon Oct  9 19:23:50 2023

@author: page
"""

import pandas as pd
import os

# 设置txt文件所在目录
txt_dir = '/Users/page/Documents/-文稿/1-学习/1-理学/3-化学科学/大3上-物理化学实验/1-实验10/实验数据'

# 创建一个空的DataFrame用于存储数据
df = pd.DataFrame()

# 遍历目录下的所有txt文件
for file in os.listdir(txt_dir):
    if file.endswith('.txt'):
        # 读取txt文件并将数据添加到DataFrame中
        txt_path = os.path.join(txt_dir, file)
        data = pd.read_csv(txt_path, delimiter='     ', encoding='gbk')
        df = df._append(data)

# 将DataFrame保存为Excel文件
df.to_excel('output.xlsx', index=False)
