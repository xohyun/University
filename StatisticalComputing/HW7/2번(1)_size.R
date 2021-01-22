#[CODE 2]
rm(list = ls()) 
options(warn=-1)
library(tictoc)
library(parallel)
#n_vec<-c(25,50,100,200)
n_vec <- 25
iter_num<-200
B<-1000
alpha<-0.05

bootfun<-function(n){
  test_boot<-numeric(iter_num)
  for (j in 1:iter_num)
  {
    p<-rbinom(n,1,0.5)
    x<-p*rnorm(n,-0.5,0.2)+(1-p)*rnorm(n,0.5,0.2)
    y<-rnorm(n,0,sqrt(0.29))
    z<-c(x,y)
    v<-ks.test(x,y)$statistic
    vstar<-numeric(B)
    for(b in 1:B){
      xstar<-sample(z,n,replace = T)
      ystar<-sample(z,n,replace = T)
      vstar[b]<-ks.test(xstar,ystar)$statistic
    }
    test_boot[j]<-as.integer(mean(vstar>=v)<alpha)
  }
  return(mean(test_boot))
}


nworkers <- 4
tic(paste("bootstrapping using parLapply and", nworkers, "workers"))

#[Your code]
x <- y <- z <- v <- numeric()
test_boot <- numeric()
n <- numeric

bootpar <- function(n_vec) {
  n <- n_vec
  cl <- makeCluster(nworkers)    
  clusterSetRNGStream(cl, 1001)
  
  res_parLapply <- parLapply(cl, n_Vec, function(trial) {
    p<-rbinom(n,1,0.5)
    x<-p*rnorm(n,-0.5,0.2)+(1-p)*rnorm(n,0.5,0.2)
    y<-rnorm(n,0,sqrt(0.29))
    z<-c(x,y)
    v<-ks.test(x,y)$statistic
    vstar<-numeric(B)
    for(b in 1:B){
      xstar<-sample(z,n,replace = T)
      ystar<-sample(z,n,replace = T)
      vstar[b]<-ks.test(xstar,ystar)$statistic
    }
    test_boot[j]<-as.integer(mean(vstar>=v)<alpha)
  })
  
   
  stopCluster(cl)  
  return (mean(test_boot))
}
with_time <- toc()
microbenchmark(bootfun(n_vec), bootpar(n_vec))

