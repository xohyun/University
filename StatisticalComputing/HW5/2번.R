library(stats4)
set.seed(12345)
n <- 50
m <- 10000
mse <- matrix(0, 1, 3)
colnames(mse) <- c("sample mean", "sample median", "mle")

calculate_mse <- function(n, m) {
  x_mean <- numeric(m)
  x_median <- numeric(m)
  x_mle <- numeric(m)
  
  mlogL <- function(theta) {
    nlk <- length(x)*log(pi) + sum(log(1+(x-theta)^2))
    return(nlk)
  }
  
  for (i in 1:m) {
    x <- rcauchy(n, location =  2, scale = 1)
    x_mean[i] <- mean(x)
    x_median[i] <- median(x)
    x_mle[i] <- mle(mlogL, start = list(theta = 1))@coef
  }
  
  mse.mean <- mean((x_mean-2)^2)
  mse.median <- mean((x_median-2)^2)
  mse.mle <- mean((x_mle-2)^2)
  
  return (c(mse.mean, mse.median, mse.mle))
}
mse[1, 1:3] <- calculate_mse(n = n, m = m)
print(mse)