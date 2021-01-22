library(stats4)
library(numDeriv)
alpha <- 0.05
c <- qnorm(1-alpha/2)

mlogL <- function(theta) {
  nlk <- -1997 * log(2 + theta) - 1810 * log(1 - theta) - 32 * log(theta)
  return (nlk)
}
t <-mle(mlogL, start = list(theta = 0.5), method = "L-BFGS-B", lower = 0+1e-8, upper = 1-1e-8)
se <- sqrt(diag(t@vcov))

LCL <- t@coef-c*se
UCL <- t@coef+c*se
result <- cbind(LCL, UCL)
t@coef
result

#그래프 그리기
lambda_gr <- seq(0, 1, 0.0001)
lambda_mle_approx <- lambda_gr[which.min(mlogL(lambda_gr))]

plot(lambda_gr, mlogL(lambda_gr), type = "l")
lambda_mle_approx

theta_mle

#t <-optim(0.5, mlogL, method= "Brent", lower = 0, upper = 1)
#se <- sqrt(diag(solve(hessian(mlogL, x=t$par))))
# LCL <- t$par-c*se
# UCL <- t$par+c*se
# result <- cbind(LCL, UCL)



# t <- mle(mlogL_deriv, start = list(theta = 0.5))
# 
# 
# library(stats4)
# library(numDeriv)
# alpha <- 0.05
# c <- qnorm(1-alpha/2)
# 
# mlogL <- function(theta) {
#   nlk <- -1997 * log(2 + theta) - 1810 * log(1 - theta) - 32 * log(theta)
#   return (nlk)
# }
# mlogL_deriv <- function (theta) {
#   grad(mlogL, theta)
# }
# 
# newton <- function(fun, tol = 0.001, x0 = 0.5, N = 300) {
#   i <- 1
#   x1 <- x0
#   p <- numeric(N)
#   while(i <= N) {
#     df.dx <- grad(fun, x0)
#     x1 <- (x0 - (fun(x0) / df.dx))
#     p[i] <- x1
#     i = i + 1
#     if(abs(x1 - x0) < tol) break
#     x0 = x1
#   }
#   return(p[1:(i-1)])
# }
# res <- newton(mlogL_deriv, x0 = 0.5)
# theta_mle <- res[length(res)]