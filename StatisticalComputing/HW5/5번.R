alpha <- 0.05
c <- qnorm(1-alpha/2)
theta_init = c(0.5, 0.5)

mlogL <- function(theta){
  p <- theta[1]
  d <- theta[2]
  nlk <- -32*log(p - d*p + d*p^2) - 41*log(2*d*p) - 41*log(1-p) - 36*log((1-d)*(1-p) + d*(1-p)^2)
  return (nlk)
}

mlogL_deriv <- function(theta){
  grad(mlogL, theta)
}

newton_mul <- function(fun, tol = 1e-7, x0, N = 300) {
  i <- 1
  x1 <- x0
  p <- matrix(0, length(x0), N)
  while (i <= N) {
    df.dx <- jacobian(fun, x0)
    x1 <- x0 - solve(df.dx) %*% fun(x0)
    p[,i] <- x1
    i = i + 1
    if(sum(abs(x1 - x0)) < tol) break
    x0 = x1
  }
  return(p[, 1:(i-1)])
}

res_mul <- newton_mul(mlogL_deriv, x0 = theta_init)
theta_mle <- res_mul[,dim(res_mul)[2]]
se <- sqrt(diag(solve(hessian(mlogL, x=theta_mle))))

LCL <- theta_mle-c*se
UCL <- theta_mle+c*se
result <- cbind(LCL, UCL)
rownames(result) <- c("p", "d")
theta_mle
result


#mle(mlogL,start=list(p=0.5, d=0.5))