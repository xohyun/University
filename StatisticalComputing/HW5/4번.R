library(stats4)
x <- c(34, 25, 12, 5, 1, 0)
f <- rep(1:6)
lambda_init <- sum(x * f) / sum(x)
result <- matrix(0,1,2)
nlk <- 0
mlogL <- function(lambda) {
  for (i in 1:length(x)) {
    nlk <- nlk + x[i] * (-lambda + i * log(lambda) - log(1 - exp(-lambda)))
  }
  nlk <- -nlk
  return (nlk)
}
t <- mle(mlogL, start = list(lambda = lambda_init), method = "L-BFGS-B", lower = 0+1e-8)
result[1] <- t@coef
result[2] <- sqrt(diag(t@vcov))
colnames(result) <- c("mle", "se")
t@coef
result

# 그래프 그려보기
lambda_gr <- seq(0, 10, 0.1)
lambda_mle_approx <- lambda_gr[which.min(mlogL(lambda_gr))]
plot(lambda_gr, mlogL(lambda_gr), type = "l")
abline(v = lambda_mle_approx, col = 2, lty = 2)