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


loglik <- function(theta) {
  a1 <- theta[1]
  a2 <- theta[2]
  a3 <- 1 - a1 - a2
  #theta[3]
  n1 <- n * a1 / (a1 + a2 + a3)
  n2 <- n * a2 / (a1 + a2 + a3)
  n3 <- n * a3 / (a1 + a2 + a3)
  #nlk <- -n1 * ((y-theta[4])^2)/(2 * theta[5]) - n2 * ((y - theta[6])^2)/(2 * theta[7]) -  n3 * ((y - theta[8])^2)/(2 * theta[9])
  nlk <- sum(a1 * (-(y-theta[4])^2/(2*theta[5])-log(theta[5])) + a2 * (-(y-theta[6])^2/(2*theta[7])-log(theta[7])) + a3 * (-(y-theta[8])^2/(2*theta[9])-log(theta[9])))
  + sum(a1 * log(a1) + a2 * log(a2) + a3 * log(a3))
  return(nlk)
}

optim(c(0.5, 0.5, 0.5, 0, 0.5, 0, 0.5, 0, 0.5), loglik, method="L-BFGS-B", lower = c(0,0,0,-Inf,0,-Inf,0,-Inf,0), upper = c(1,1,1,Inf,Inf,Inf,Inf,Inf,Inf))