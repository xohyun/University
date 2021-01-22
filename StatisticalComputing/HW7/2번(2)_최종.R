rm(list = ls())
options(warn = -1)
B <- 1000
alpha <- 0.05
iter_num <- 200
nworkers <- 4
tic(paste("bootstrapping using parLapply and", nworkers, "workers"))
n_vec <- c(25, 50, 100, 200)
n <- numeric()
test_boot <- numeric()

bootpar <- function(n) {
  cl <- makeCluster(nworkers)    
  clusterSetRNGStream(cl, 1001)
  clusterExport(cl, c("n", "B", "alpha", "iter_num", "test_boot"))  
  
  res_parLapply <- parLapply(cl, 1:iter_num, function(trial){
    p <- rbinom(n, 1, 0.5)
    x <- p*rnorm(n, -0.5, 0.2) + (1-p)*rnorm(n, 0.5, 0.2)
    y <- rnorm(n, 0, sqrt(0.29))
    z <- c(x, y)
    v <- ks.test(x, y)$statistic
    vstar <- numeric(B)
    
    for (b in 1:B) {
      xstar <- sample(z, n, replace = TRUE)
      ystar <- sample(z, n, replace = TRUE)
      vstar[b] <- ks.test(xstar, ystar)$statistic
    }
    test_boot <- as.integer(mean(vstar>=v)<alpha)
    return(test_boot)
  })
  stopCluster(cl)   
  return (mean(unlist(res_parLapply)))
}

result <- numeric(4)
p <- 1
for (n in n_vec) {
  result[p] <- bootpar(n)
  p<-p+1
}
with_time <- toc()
result