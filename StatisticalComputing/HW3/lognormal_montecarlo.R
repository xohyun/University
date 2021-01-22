n <- 30
alpha <- 0.05

CL <- replicate(10000, expr = {
  #x <- rlnorm(n = n, meanlog = 0, sdlog = 1)
  y <- rnorm(n, mean = 0, sd = 1)
  #x <- exp{y}
  
  LCL <- mean(y) - qt(1-alpha/2, df = n - 1)*sqrt(var(y))/sqrt(n)
  UCL <- mean(y) + qt(1-alpha/2, df = n - 1)*sqrt(var(y))/sqrt(n)
  c(LCL, UCL)
})
mean(CL[1,] < 0 & CL[2,] > 0)

################################################################

n <- 30
alpha <- 0.05

CL <- replicate(10000, expr = {
  #x <- rlnorm(n = n, meanlog = 0, sdlog = 1)
  y <- rnorm(n, mean = 0, sd = 1)
  x <- exp(y)
  
  LCL <- mean(x) - qt(1-alpha/2, df = n - 1)*sqrt((exp(1)-1)*exp(1))/sqrt(n)
  UCL <- mean(x) + qt(1-alpha/2, df = n - 1)*sqrt((exp(1)-1)*exp(1))/sqrt(n)
  c(LCL, UCL)
})

mean(CL[1,] < exp(1/2) & CL[2,] > exp(1/2))

################################################################
#¿Ã∞…∑Œ!

#y <- rnorm(n, mean = 0, sd = 1)
#x <- exp{y}
set.seed(12345)
n <- 30
alpha <- 0.05

CL <- replicate(10000, expr = {
  x <- rlnorm(n = n, meanlog = 0, sdlog = 1)
  lnX <- log(x)
  
  s_double <- sum((lnX - mean(lnX))^2) / (n - 1)
  
  LCL <- mean(lnX) - qt(1-alpha/2, df = n - 1)*sqrt(s_double)/sqrt(n)
  UCL <- mean(lnX) + qt(1-alpha/2, df = n - 1)*sqrt(s_double)/sqrt(n)
  
  c(LCL, UCL)
})
mean(CL[1,] < 0 & CL[2,] > 0)

























