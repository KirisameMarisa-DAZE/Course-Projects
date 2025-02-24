library(shiny)
library(ggplot2)

# UI部分
ui <- fluidPage(
  titlePanel("中心极限定理数值模拟实验"),
  sidebarLayout(
    sidebarPanel(
      selectInput("distribution", "抽样分布：",
                  choices = c("二项分布" = "binomial",
                              "正态分布" = "normal",
                              "均匀分布" = "uniform",
                              "指数分布" = "exponential",
                              "泊松分布" = "poisson",
                              "卡方分布" = "chisq"),
                  selected = "binomial"),
      sliderInput("sample_size", "样本数：", min = 1, max = 200, value = 10),
      sliderInput("experiment_count", "实验次数：", min = 1, max = 10000, value = 1000),
      numericInput("seed", "种子：", value = 123),
      sliderInput("bin_count", "直方图窗口数：", min = 10, max = 50, value = 30),
      radioButtons("histogram_type", "直方图纵轴：",
                   choices = c("频率", "频数"), selected = "频率")
    ),
    mainPanel(
      plotOutput("histogram"),
      plotOutput("qqplot")
    )
  )
)

# Server部分
server <- function(input, output) {
  output$histogram <- renderPlot({
    set.seed(input$seed)
    dist <- switch(input$distribution,
                   "binomial" = rbinom(input$experiment_count, input$sample_size, 0.5),
                   "normal" = rnorm(input$experiment_count),
                   "uniform" = runif(input$experiment_count),
                   "exponential" = rexp(input$experiment_count),
                   "poisson" = rpois(input$experiment_count, 1/3),
                   "chisq" = rchisq(input$experiment_count, 8))
    
    if (input$histogram_type == "频率") {
      hist_type <- "density"
      hist_main <- "Histogram with Density Estimation"
    } else {
      hist_type <- "count"
      hist_main <- "Histogram"
    }
    
    ggplot(data.frame(x = dist), aes(x)) +
      geom_histogram(aes(y = ..hist_type..), binwidth = diff(range(dist)) / input$bin_count, fill = "skyblue", color = "black") +
      ggtitle(hist_main) +
      if (input$histogram_type == "频率") {
        stat_density(geom = "line", color = "red", size = 1)
      } else {
        NULL
      }
  })
  
  output$qqplot <- renderPlot({
    set.seed(input$seed)
    dist <- switch(input$distribution,
                   "binomial" = rbinom(input$experiment_count, input$sample_size, 0.5),
                   "normal" = rnorm(input$experiment_count),
                   "uniform" = runif(input$experiment_count),
                   "exponential" = rexp(input$experiment_count),
                   "poisson" = rpois(input$experiment_count, 1/3),
                   "chisq" = rchisq(input$experiment_count, 8))
    
    qqnorm(dist)
    qqline(dist, col = "red")
    title("QQ Plot")
  })
}

shinyApp(ui = ui, server = server)