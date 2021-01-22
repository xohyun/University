library(numDeriv)
set.seed(123)
n <- 1000000; num_iters <- 1000; alpha <- 0.5
x1 <- rnorm(n); x2 <- rnorm(n); x3 <- rnorm(n)
z <- 1 + 0.5 * x1 - 0.4 * x2 + 0.7 * x3
pr <- 1/(1+exp(-z))
y <- rbinom(n, 1, pr)
df <- data.frame(y = y, x1 = x1, x2 = x2, x3 = x3)

num <- numeric(num_iters)
test <- matrix(0,num_iters, 4)
beta <- matrix(c(0,0,0,0), nrow = 4)
x <- numeric(3)
theta_history <- list(num_iters + 1)

for (i in 1:num_iters) {
  data <- sample(1:n, num_iters, replace = T)
  test <- df[data,]
  test_y <- as.matrix(subset(test, select = y))
  test_x <- as.matrix(subset(test, select = c(x1, x2, x3)))
  
  mlogL <- function(beta) {
    lam <- 1 / (1+exp(-cbind(1,test_x) %*% beta))
    nlk <- (-1)*(mean(log(lam)*test_y + log(1-lam)*(1-test_y)))
    return (nlk)
  }
  delta <- grad(mlogL, beta)
  beta <- beta - alpha * delta
}
rownames(beta) <- c("beta0", "beta1", "beta2", "beta3")
colnames(beta) <- "estimate"
beta



#beta <- data.frame(beta)
#ttt <- as.matrix(cbind(1, test))
#lam <- 1/(1+exp(-ttt %*% beta))


#lam <- 1/(1+exp(-(beta[1] + beta[2]*x1+beta[3]*x2 + beta[4]*x3)))
# x1<-test_x[,1]
# x2<-test_x[,2]
# x3<-test_x[,3]

#beta <- data.frame(col1 = theta)