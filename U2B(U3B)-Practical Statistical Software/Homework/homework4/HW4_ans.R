ui <- fluidPage(
  titlePanel("中心极限定理"),
  sidebarLayout(
    sidebarPanel(
      selectInput('dist', '抽样分布', c("正态分布", "均匀分布", "二项分布", "卡方分布","泊松分布", "柯西分布")),
      sliderInput("m", "样本数", 10, min = 1, max = 200),
      sliderInput("n", "实验次数", 1000, min = 1, max = 10000),
      numericInput("seed", "种子",  123),
      sliderInput("bins",
                  "直方图窗格的个数",
                  min = 10,
                  max = 50,
                  value = 30),
      radioButtons("freq", "直方图的纵轴", c("频率","频数"))
    ),
    mainPanel(
      plotOutput("hist"),
      plotOutput("qqplot")
    )
  )
)
gendata <- function(dist, n){
  switch (dist, 
                  正态分布 = rnorm(n),
                  均匀分布 = runif(n),
                  二项分布 = rbinom(n, size = 8, prob = 0.5),
                  卡方分布 = rchisq(n, df = 8),
                  泊松分布 = rpois(n, lambda = 1/3),
                  柯西分布 = rcauchy(n)
  )# 2分
}
server <- function(input, output, session) {
  output$hist <- renderPlot({
    set.seed(input$seed)
    x <- replicate(input$n, gendata(input$dist,input$m))
    meanx <- apply(x, 2, mean)
    bins <- seq(min(meanx), max(meanx), length.out = input$bins + 1)
    
    if(input$freq == "频率"){
      hist(meanx, breaks = bins, freq = FALSE, main = paste0("均值的直方图（基于", input$n, "次的实验）"), 
           xlab = "", ylab ="频率")
      lines(density(meanx), col="red")
    } else{
      hist(meanx, breaks = bins, freq = TRUE, main = paste0("均值的直方图（基于", input$n, "次的实验）"),
           xlab = "", ylab ="频数")
    }
  })
  
  output$qqplot <- renderPlot({
    set.seed(input$seed)
    x <- replicate(input$n, runif(input$m))
    meanx <- apply(x, 2, mean)
    qqnorm(meanx, main = "QQ图（与标准正态分布比较）")
  })
   
}
shinyApp(ui, server)