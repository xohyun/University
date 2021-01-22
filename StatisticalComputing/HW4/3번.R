set.seed(12345)
size <- c(25, 50, 100, 200)
num_iter <- 1000
B <- 1000
power <- numeric(length(size)); power2 <- numeric(length(size))
pvalue2 <- numeric(num_iter)
k <- 1
alpha <- 0.05
for (s in size) {
  counter1 <- 0
  count.boot <- 0
  for (i in 1:num_iter) {
    counter2 <- 0
    p <- rbinom(s, 1, 0.5)
    x <- p*rnorm(s, -0.5, 0.2) + (1-p)*rnorm(s, 0.5, 0.2)
    y <- rnorm(s, 0, sqrt(0.29))
    z <- c(x, y)
    
    p_value1 <- ks.test(x,y)$p.value
    if (p_value1 < alpha) {counter1 <- counter1 + 1}
    
    v <- ks.test(x, y)$statistic
    for (b in 1:B) {
      xstar <- sample(z, s, replace = T)
      ystar <- sample(z, s, replace = T)
      vstar <- ks.test(xstar, ystar)$statistic
      if(vstar >= v) {counter2 <- counter2 + 1}
    }
    pvalue2[i] <- counter2 / B
    if (pvalue2[i] < alpha) {count.boot <- count.boot + 1}
  }
  power[k] <- counter1 / num_iter
  power2[k] <- count.boot / num_iter
  k <- k + 1
}
result <- cbind(power, power2)
rownames(result) <- size
colnames(result) <- c("ks.test사용시", "bootstrap 사용시")
result