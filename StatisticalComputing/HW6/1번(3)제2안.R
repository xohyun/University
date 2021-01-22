rm(list = ls()) # remove all objects in R before starting our own work
library("dplyr")
library("reshape2")

options(scipen = 999)

# data generation from 0.5 N(-1,0.6^2)+ 0.3 N(0.5,0.3^2) + 0.2 N(2,0.3^2)
n<-400

pi1<-0.5; pi2<-0.3; pi3<-0.2

mu1<--1; sigma1<-0.6
mu2<-0.5; sigma2<-0.3
mu3<-2; sigma3<-0.3

set.seed(20200607)  
x1<-rnorm(n,mu1,sigma1)
x2<-rnorm(n,mu2,sigma2)
x3<-rnorm(n,mu3,sigma3)

Delta<-t(rmultinom(n, 1, c(pi1,pi2,pi3)))
y <- apply(cbind(x1,x2,x3)*Delta,1,sum)


y.kmeans <- kmeans(y, 3)
y.kmeans.cluster <- y.kmeans$cluster # for a very good initial
#y.kmeans.cluster <- ifelse(y<=median(y), 1, 2) # for a naive initial
y.df <- data.frame(x = y, cluster = y.kmeans.cluster)

# #######################333
a1 <- length(y.df[y.df$cluster=="1",]$x)
a2 <- length(y.df[y.df$cluster=="2",]$x)
a3 <- length(y.df[y.df$cluster=="3",]$x)
#######################
y1 <- y.df[y.df$cluster=="1",]$x
y2 <- y.df[y.df$cluster=="2",]$x
y3 <- y.df[y.df$cluster=="3",]$x


loglik <- function(theta) {
  a1 <- theta[1]
  a2 <- theta[2]
  a3 <- theta[3]
  
  n1 <- a1 / (a1 + a2 + a3)
  n2 <- a2 / (a1 + a2 + a3)
  n3 <- 1- n1- n2 
    #a3 / (a1 + a2 + a3)
 
  #nlk <- -n1 * ((y-theta[4])^2)/(2 * theta[5]) - n2 * ((y - theta[6])^2)/(2 * theta[7]) -  n3 * ((y - theta[8])^2)/(2 * theta[9])
  
  # nlk <- sum(n1 * (-(y-theta[4])^2/(2*(theta[5]^2)-log(theta[5]^2)) 
  #                  + n2 * (-(y-theta[6])^2/(2*(theta[7]^2))-log(theta[7]^2)) 
  #                  + n3 * (-(y-theta[8])^2/(2*(theta[9]^2))-log(theta[9]^2))))
  #                  + sum(n1 * log(a1) + n2 * log(a2) + n3 * log(a3))
  
  nlk <- sum(n1 * (-2 * log(theta[5])-(y1-theta[4])^2/(2*(theta[5]^2))))
        + sum(n2 * (-2 * log(theta[7])-(y2-theta[6])^2/(2*(theta[7]^2)))) 
        + sum(n3 * (-2 * log(theta[9])-(y3-theta[8])^2/(2*(theta[9]^2))))  
        + sum(n1 * log(a1) + n2 * log(a2) + n3 * log(a3))
  
  return(-nlk)
}
e <- 1e-10
 # m1 <- mean(y.df$cluster == "1")
 # m2 <- mean(y.df$cluster == "2")
 # m3 <- mean(y.df$cluster == "3")
# theta<-c(0.33, 0.33, 0.34, mean(x1), mean(var(x1)), mean(x2), mean(var(x2)), mean(x3), mean(var(x3)))
theta<-c(a1/400, a2/400, a3/400, mean(y1), var(y1), mean(y2), var(y2), mean(y3), var(y3))
#theta<-c(0.34,0.34,0.32,0,1,0,1,0,1)
res<-optim(theta, loglik, method="L-BFGS-B", lower = c(0,0,0,-Inf,e,-Inf,e,-Inf,e), upper = c(1,1,1,Inf,Inf,Inf,Inf,Inf,Inf))
res$par[1]+res$par[2]+res$par[3]
res