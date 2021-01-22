library(ggplot2)

m <- 1000
mu0 <- 500
sigma <- 100
mu <- c(seq(450, 650, 10))
M <- length(mu)
size <- c(10, 20, 30, 40, 50)
gg <- ggplot(df, aes(x = mean, y = power))
power <- numeric(0)

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
  k <- ggplot(df, aes(x = mean, y = power)) +
    geom_line(color = n) +
    geom_vline(xintercept = 500, lty = 2) +
    geom_hline(yintercept = c(0, 0.05), lty = 1:2) +
    geom_errorbar(aes(ymin = lower, ymax = upper), width = 0.2, lwd = 1.5)
  gg <- gg + k
}

