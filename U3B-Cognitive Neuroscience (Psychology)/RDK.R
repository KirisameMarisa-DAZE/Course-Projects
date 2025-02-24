library(tidyverse)
library(afex)
library(emmeans)
library(ggplot2)

# 读取数据
data <- read.csv("RDK.csv")

# 查看数据结构
head(data)

# 确保数据格式正确
names(data) <- c("Condition", "Correct", "Reaction_Time")

# 创建一个虚拟受试者ID
data$Subject <- rep(1:(nrow(data)/length(unique(data$Condition))), each = length(unique(data$Condition)))

# 查看数据结构
head(data)

# 转换数据框为适合aov函数的格式
data_long <- data %>%
  pivot_longer(cols = c("Reaction_Time"),
               names_to = "Measure",
               values_to = "Value")

# 确保列名正确
head(data_long)

# 执行重复测量方差分析
anova_results <- aov(Value ~ Condition + Error(Subject/Condition), data = data_long)

# 查看结果
summary(anova_results)

# 事后分析
post_hoc <- emmeans(anova_results, pairwise ~ Condition)

# 查看事后分析结果
summary(post_hoc)

# 绘制箱线图
ggplot(data, aes(x = Condition, y = Reaction_Time)) +
  geom_boxplot() +
  labs(title = "Reaction Time by Condition", x = "Condition", y = "Reaction Time (s)") +
  theme_minimal()