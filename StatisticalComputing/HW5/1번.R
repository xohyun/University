library(stats4)
set.seed(12345)

n <- 100
m <- 10000
alpha <- 0.05
counter <- 0
c <- qnorm(1-alpha/2)
LCL <- matrix(0, n, 1)
UCL <- matrix(0, n, 1)

mlogL <- function(theta) {
  nlk <- length(x) * log(pi) + sum(log(1+(x-theta)^2))
}

for (i in 1:m) {
  x <- rcauchy(n, scale = 1, location = 2)
  fit <- mle(mlogL, start = list(theta = median(x)))
  LCL[i] <- fit@coef-c*sqrt(diag(fit@vcov))
  UCL[i] <- fit@coef+c*sqrt(diag(fit@vcov))
  
  if (LCL[i] <= 2 & 2 <= UCL[i]) {counter = counter + 1}
}
counter/m
