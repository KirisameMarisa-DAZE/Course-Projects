set.seed(123)
n <- 5000
x.sam <- runif(n, min = 0, max = 1)
y.sam <- runif(n, min = 0, max = 1)

mu_hat <- 4*cumsum(x.sam^2 + y.sam^2 < 1)/(1:n)

library(ggplot2)
p1 <- ggplot(mapping = aes(1:n, mu_hat)) + 
  geom_point() + 
  geom_line() +
  geom_hline(aes(yintercept = pi), color = "gray", linewidth=1.5, linetype = "dashed") + 
  coord_cartesian(ylim = c(2, 5))


joint.data <- data.frame(x = x.sam, y = y.sam)
joint.data$Accepted <- (joint.data$x^2 + joint.data$y^2 < 1)

plot_ar <- ggplot(joint.data, aes(x=x, y=y)) + 
  geom_point(shape=20, aes(color=Accepted)) +
  stat_function(fun = function(x) sqrt(1-x^2), size=1.5) + 
  geom_hline(aes(yintercept = 0)) +
  coord_fixed() +
  geom_segment(aes(x = 0, y = 0, xend = 1, yend = 0), colour = "black", size = 1.5) + 
  annotate("segment", x = 0, xend = 0, y = 0, yend = 1,colour = "black", size = 1.5)


# beautify : Increase font size in axes 
p2 <- plot_ar + theme(axis.text.x = 
                  element_text(face = "bold",size = 12),
                axis.text.y = 
                  element_text(face = "bold", size = 12),
                axis.line = element_line(colour = "black", 
                                         size = 1, linetype = "solid"))

library(gridExtra)
grid.arrange(p1, p2, nrow = 1)


###
x <- seq(-3, 3, 0.2)
lam <- 1
myfun <- function(x, lam = 1) ifelse(abs(x)<=lam, 0, sign(x)*(abs(x)-lam))
y <- sign(x) * pmax(abs(x)-lam, 0)
y <- myfun(x)
plot(x, y, type="l")
abline(a = 0, b= 1, col="gray", lty= 2)


###
set.seed(123)
beta <- c(1,0)
n <- 1000
x <- matrix(rnorm(n*2), n,2)
y <- x%*%beta + rnorm(n,0, 0.5)

beta_hat <- rep(0,2) #solve(t(x)%*%x) %*%t(x)%*%y
xx <- apply(x^2, 2, sum)
xy <- t(x) %*%y 
lam <- 0.5

beta_ini <- rep(0, 2)
beta_diff <- 1
while(beta_diff >1e-6){
  for(i in 1:2){
    beta_hat[i] <- myfun(sum(x[,i]*(y - x[,-i]*beta_hat[-i])),  lam)/xx[i]
  }
  beta_diff <- sum((beta_hat - beta_ini)^2)
  beta_ini <- beta_hat
  print(beta_hat)
}

mse1 <- mean((beta_hat - beta)^2)


