set.seed(12345)
size <- c(25, 50, 100, 200, 400)
num_iter <- 10000
t_store <- numeric(10000); ks_store <- numeric(10000)
power <- numeric(length(size)); power2 <- numeric(length(size))
k <- 1
alpha <- 0.05
for (s in size) {
  counter <- 0
  counter2 <- 0
  for (i in 1:num_iter) {
    p <- rbinom(s, 1, 0.5)
    x <- p*rnorm(s, -0.5, 0.2) + (1-p)*rnorm(s, 0.5, 0.2)
    y <- rnorm(s, 0, sqrt(0.29))
   
    t_store[i] <- t.test(x, y, var.equal = TRUE)$p.value
    if (t_store[i] < alpha) {counter <- counter + 1}
    
    ks_store[i] <- ks.test(x, y)$p.value
    if (ks_store[i] < alpha) {counter2 <- counter2 + 1}
  }
  power[k] <- (counter / num_iter)
  power2[k] <- (counter2 / num_iter)
  k <- k + 1
}
result <- cbind(power, power2)
colnames(result) <- c("t-test", "KS-test")
rownames(result) <- size
result
