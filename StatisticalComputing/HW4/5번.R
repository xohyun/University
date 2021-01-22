set.seed(12345)
B <- 10000
cards <- c(rep(1, 60), rep(0, 140))
teststatall <- numberic(B)

for (b in 1:B) {
  experiment <- sample(cards)
  teststatall[b] <- mean(experiment[1:100]) - mean(experiment[101:200])
}

hist(teststatall, nclass = "scott", xlab = "", main = "", freq = FALSE)
mean(teststatall <= -0.2)

###################
set.seed(12345)
B <- 1000
teststatall <- numeric(B)
x <- c(94, 38, 23, 197, 99, 16, 141)
y <- c(52, 10, 40, 104, 51, 27, 146, 30, 46)
data <- c(x, y)

for (b in 1:B) {
  mix <- sample(data)
  treatment <- mix[1:7]
  control <- mix[8:16]
  teststatall[b] <- mean(treatment) - mean(control)
}

hist(teststatall, nclass = "scott", main = "", xlab = "", freq = FALSE)
points(30.64, 0, cex = 1, pch = 16, col = 2)
mean(teststatall >= 30.64)

###################
set.seed(12345)
x <- c(94, 197, 16, 38, 99, 141, 23)
y <- c(52, 104, 146, 10, 51, 30, 40, 27, 46)
z <- c(x, y)

equal_boot <- function(z, ix, dims) {
  zstar <- z[ix]
  xstar <- zstar[1:dims[1]]
  ystar <- zstar[(dims[1] + 1):(dims[1]+dims[2])]
  return(mean(xstar) - mean(ystar))
}
boot.obj <- boot(data = z, statistic = equal_boot, R = 1000, sim = "permutation", dims=c(length(x), length(y)))
tb <- c(boot.obj$t0, boot.obj$t)
mean(tb >= boot.obj$t0)
