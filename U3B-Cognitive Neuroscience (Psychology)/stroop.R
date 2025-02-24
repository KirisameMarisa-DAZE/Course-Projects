library(tidyverse)

# 读取数据
data <- read.csv("stroop.csv")

# 查看数据结构
head(data)
str(data)

# 确保数据格式正确
names(data) <- c("type", "keyStroop.corr", "keyStroop.rt")

# 查看数据结构
head(data)

# 将数据分为两个类型
congruent <- data %>% filter(type == "congruent") %>% select(keyStroop.rt)
incongruent <- data %>% filter(type == "incongruent") %>% select(keyStroop.rt)

# 确保每个类型的数据点数目相同
if (nrow(congruent) != nrow(incongruent)) {
  stop("每个类型的数据点数目不同，无法进行配对样本t检验")
}

# 执行配对样本t检验
t_test_results <- t.test(congruent$keyStroop.rt, incongruent$keyStroop.rt, paired = TRUE)

# 查看结果
print(t_test_results)