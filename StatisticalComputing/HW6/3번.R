library("mixtools")
library("stats4")
iter_num <- 100
sel_comp <- numeric(iter_num)
set.seed(20200607)

n <- 400
pi1 <- 0.5; pi2 <- 0.3; pi3 <- 0.2
mu1 <- -1; sigma1 <- 0.6
mu2 <- 0.5; sigma2 <- 0.3
mu3 <- 2; sigma3 <- 0.3

for (iter in 1:iter_num) {
  cat("Iteration number #", iter, "\n")
  
  x1 <- rnorm(n, mu1, sigma1)
  x2 <- rnorm(n, mu2, sigma2)
  x3 <- rnorm(n, mu3, sigma3)
  Delta <- t(rmultinom(n, 1, c(pi1, pi2, pi3)))
  y <- apply(cbind(x1, x2, x3)*Delta, 1, sum)
  
  ####code####
  bic <- numeric()
  
  for (i in 2:10) {
    mixmdl <- normalmixEM(y, k = i, maxit = 10000, maxrestarts = 1000, epsilon = 1e-06, 
                          lambda = NULL, mu = NULL, sigma = NULL)
    likelihood <- mixmdl$loglik
    numberOfParameters <- i * 3 - 1 #모수의 수
    bic[i] <- (-2) * likelihood + numberOfParameters * log(n)
  }
  sel_comp[iter] <- which.min(bic)
}
table(sel_comp)