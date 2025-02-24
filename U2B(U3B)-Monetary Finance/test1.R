# 加载必要的包
library(xts)
library(zoo)
library(tseries)
library(rugarch)
library(forecast)
library(tidyverse)
library(lubridate)
library(PerformanceAnalytics)


# 数据读取与清洗

### 读取CSV文件
data <- read_csv("JPY_CNY.csv")

### 检查并修正列名
colnames(data) <- c("Date", "Close", "Open", "High", "Low", "Volume", "Change")

### 数据清洗
data <- data %>%
  # 转换日期格式
  mutate(Date = ymd(Date)) %>%
  # 去除缺失值
  drop_na(Close) %>%
  # 检查并处理重复值
  distinct() %>%
  # 确保收盘价和涨跌幅为数值型数据
  mutate(
    Close = as.numeric(Close),
    Open = as.numeric(Open),
    High = as.numeric(High),
    Low = as.numeric(Low),
    Change = as.numeric(str_replace(Change, "%", "")) / 100
  )


# 描述性统计分析
summary_stats <- data %>%
  summarise(
    Mean_Close = mean(Close, na.rm = TRUE),
    SD_Close = sd(Close, na.rm = TRUE),
    Min_Close = min(Close, na.rm = TRUE),
    Max_Close = max(Close, na.rm = TRUE),
    Median_Close = median(Close, na.rm = TRUE),
    Mean_Change = mean(Change, na.rm = TRUE),
    SD_Change = sd(Change, na.rm = TRUE),
    Min_Change = min(Change, na.rm = TRUE),
    Max_Change = max(Change, na.rm = TRUE),
    Median_Change = median(Change, na.rm = TRUE)
  )

### 显示描述性统计结果
print(summary_stats)


# 时间序列分析

### 创建xts对象
xts_data <- xts(data$Close, order.by = data$Date)

### 移动平均
##### 计算12个月的移动平均
ma_12 <- rollmean(xts_data, k = 12, align = "right", fill = NA)
##### 绘制时间序列图
plot(xts_data, main = "收盘价时间序列与移动平均线", col = "blue", major.ticks = "years", minor.ticks = FALSE)
lines(ma_12, col = "red", lwd = 2)
legend("topright", legend = c("收盘价", "12个月移动平均"), col = c("blue", "red"), lty = 1)

### ARIMA模型
##### 拟合ARIMA模型
fit <- auto.arima(xts_data)
##### 生成预测
forecast_data <- forecast(fit, h = 24) # 预测未来24个数据点（例如，2年，如果是按月数据）
##### 获取最近15年的数据
end_date <- end(xts_data)
start_date <- end_date - years(15)
xts_data_last_10_years <- window(xts_data, start = start_date, end = end_date)
##### 获取对应的预测数据
forecast_dates <- seq(end_date + months(1), by = "month", length.out = 24)
forecast_data_xts <- xts(forecast_data$mean, order.by = forecast_dates)
##### 合并实际数据和预测数据
combined_data <- merge(xts_data_last_10_years, forecast_data_xts, all = TRUE)
combined_data <- na.locf(combined_data, fromLast = TRUE)
##### 绘制实际数据的时间序列图
plot(index(combined_data), coredata(combined_data[, 1]), type = "l", main = "汇率的ARIMA模型预测", col = "black", xlab = "时间", ylab = "汇率")
##### 添加预测值和置信区间
lines(index(forecast_data_xts), coredata(forecast_data_xts), col = "red", lty = 2)
lines(index(forecast_data_xts), forecast_data$lower[, 2], col = "red", lty = 3)
lines(index(forecast_data_xts), forecast_data$upper[, 2], col = "red", lty = 3)
##### 添加图例
legend("topleft", legend = c("实际数据", "预测值", "置信区间"), col = c("black", "red", "red"), lty = c(1, 2, 3), lwd = 2)


# 波动性分析

### GARCH模型
##### 构建GARCH(1, 1)模型
spec <- ugarchspec(variance.model = list(model = "sGARCH", garchOrder = c(1, 1)), mean.model = list(armaOrder = c(1, 1)))
##### 拟合模型
fit_garch <- ugarchfit(spec = spec, data = xts_data)
##### 模型摘要
summary(fit_garch)
##### 预测未来波动性
forecast_garch <- ugarchforecast(fit_garch, n.ahead = 12)
##### 绘制预测结果
plot(forecast_garch, which=3)

### EGARCH模型
##### 构建EGARCH(1, 1)模型
spec_egarch <- ugarchspec(variance.model = list(model = "eGARCH", garchOrder = c(1, 1)), mean.model = list(armaOrder = c(1, 1)))
##### 拟合模型
fit_egarch <- ugarchfit(spec = spec_egarch, data = xts_data)
##### 模型摘要
summary(fit_egarch)
##### 预测未来波动性
forecast_egarch <- ugarchforecast(fit_egarch, n.ahead = 12)
##### 绘制预测结果
plot(forecast_egarch, which=3)


# 风险分析

### VaR分析
##### 计算每日收益率
returns <- diff(log(xts_data))
##### 计算VaR
VaR_95 <- VaR(returns, p = 0.95, method = "historical")
##### 显示VaR结果
print(VaR_95)

### 情景分析和压力测试
##### 定义一个极端情景
extreme_scenario <- returns - 0.05
##### 压力测试
stress_test <- VaR(extreme_scenario, p = 0.95, method = "historical")
##### 显示压力测试结果
print(stress_test)