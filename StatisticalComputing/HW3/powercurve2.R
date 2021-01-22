m <- 1000
mu0 <- 500
sigma <- 100
mu <- c(seq(450, 650, 10))
M <- length(mu)
size <- c(10, 20, 30, 40, 50)
power <- rep(0, 21)

plot(mu, power, xlim = c(450, 650), ylim = c(0,1), xlab = "mu", ylab = "power", type = "n")
for (n in size) {
  for (i in 1:M) {
    mu1 <- mu[i]
    pvalues <- replicate(m, expr = {
      x <- rnorm(n, mean = mu1, sd = sigma)
      ttest <- t.test(x, alternative = "greater", mu = mu0)
      ttest$p.value})
    power[i] <- mean(pvalues <= 0.05)
  }
  se <- sqrt(power * (1 - power) / m)
  df <- data.frame(mean = mu, power = power, upper = power+2*se, lower = power-2*se)
  lines(mu, power, type = "o", col = which(size == n))
}

legend(c("10", "20", "30", "40", "50"), col = 1:5, lty = 1, title = "표본의 크기", x = 600, y = 0.6)
abline(v = 500, lty = 2)
abline(h = c(0, 0.05), lty = c(1, 2))