n <- 30
m <- 100000
mse <- matrix(0, 1, 3)
colnames(mse) <-c("sample mean", "sample median", "the 1st trimmed mean")

calculate_mse <- function(n, m) {
  tmean <- numeric(m)
  x_mean <- numeric(m)
  x_median <- numeric(m)
  for (i in 1:m) {
    sigma <- sample(c(1,10), size = n, replace = TRUE, prob = c(0.9, 0.1))
    x <- sort(rnorm(n, 0 , sigma))
    tmean[i] <- sum(x[2:(n-1)])/(n-2)
    x_mean[i] <- mean(x)
    x_median[i] <- median(x)
  }
  mse.tmean <- mean(tmean^2)
  mse.mean <- mean(x_mean^2)
  mse.median <- mean(x_median^2)
  
  return (c(mse.mean, mse.median, mse.tmean))
}
mse[1, 1:3] <- calculate_mse(n = n, m = m)
print(mse)