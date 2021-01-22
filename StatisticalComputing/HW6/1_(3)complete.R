rm(list = ls()) # remove all objects in R before starting our own work
# library("dplyr")
# library("reshape2")

options(scipen = 999)

# data generation from 0.5 N(-1,0.6^2)+ 0.3 N(0.5,0.3^2) + 0.2 N(2,0.3^2)
n<-400
pi1<-0.5; pi2<-0.3; pi3<-0.2

mu1<- -1; sigma1<-0.6
mu2<-0.5; sigma2<-0.3
mu3<-  2; sigma3<-0.3

set.seed(20200607)  
x1<-rnorm(n,mu1,sigma1); x2<-rnorm(n,mu2,sigma2); x3<-rnorm(n,mu3,sigma3)

Delta<-t(rmultinom(n, 1, c(pi1,pi2,pi3)))
y <- apply(cbind(x1,x2,x3)*Delta,1,sum)

y.kmeans <- kmeans(y, 3)
y.kmeans.cluster <- y.kmeans$cluster
y.df <- data.frame(x = y, cluster = y.kmeans.cluster)

y1 <- y.df[y.df$cluster=="1",]$x
y2 <- y.df[y.df$cluster=="2",]$x
y3 <- y.df[y.df$cluster=="3",]$x

loglik <- function(theta){
  a1 <- theta[1]; a2 <- theta[2]; a3 <- theta[3]
    
  phi_theta1 = a1 / (a1+a2+a3)
  phi_theta2 = a2 / (a1+a2+a3)
  phi_theta3 = 1-phi_theta1-phi_theta2
  
  nlk1 <- (-1) * sum(log(phi_theta1 * dnorm(y, theta[4], theta[5])
                        + phi_theta2 * dnorm(y, theta[6], theta[7])
                        + phi_theta3 * dnorm(y, theta[8], theta[9])))
                      
  return(nlk1)
}
theta<-c(0.33, 0.34, 0.33, mean(y1), sd(y1), mean(y2), sd(y2), mean(y3), sd(y3))

res <- optim(theta, loglik, method="L-BFGS-B", lower = c(0,0,0,-Inf,0,-Inf,0,-Inf,0), upper = c(1,1,1,Inf,Inf,Inf,Inf,Inf,Inf))
k <- res$par
res$par[1] <- k[1] / (k[1]+k[2]+k[3])
res$par[2] <- k[2] / (k[1]+k[2]+k[3])
res$par[3] <- k[3] / (k[1]+k[2]+k[3])
res$par