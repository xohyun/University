y1 <- c(1.5, 2.2, 3.3, 1.6)
N <- 100
theta <- 1
theta_vec <- numeric(N)

for (i in 1:N)
{
  theta <- mean(c(y1, theta))
  theta_vec[i] <- theta
}
plot(c(mean(y1), theta_vec), ylab = "theta")
theta




# log_lik <- function(theta)
# {
#   return (sum(log(dexp(y1, rate = 1/theta, log= FALSE))) + sum(log((1-pexp(y0,rate = 1/theta)))))
# }

#log_lik_vec <- numeric(N)
#log_lik_vec[i] <- log_lik(theta)
#par(mfrow= c(1,2))
#plot(c(log_lik(mean(y1)), log_lik_vec), ylab = "log-likelihood")