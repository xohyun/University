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
x1<-rnorm(n,mu1,sigma1); x2<-rnorm(n,mu2,sigma2); x3<-rnorm(n,mu3,sigma3)

Delta<-t(rmultinom(n, 1, c(pi1,pi2,pi3)))
y <- apply(cbind(x1,x2,x3)*Delta,1,sum)

y.kmeans <- kmeans(y, 3)
y.kmeans.cluster <- y.kmeans$cluster #for a very good initial

y.df <- data.frame(y = y, cluster = y.kmeans.cluster)

y.summary.df <- y.df %>%
  group_by(cluster) %>%
  summarize(mu = mean(y), std = sd(y), size = n())

y.summary.df %>%
  select(cluster, mu, std)

y.summary.df <- y.summary.df %>%
  mutate(alpha = size / sum(size)) #alha is pi in the lecture slide

y.summary.df %>%
  select(cluster, size, alpha)

y.summary.df #여기에 초기치에 대한 정보가 들어 있음
##########################################################
# log-likelihood after E-step and M-step 
e_step <- function(y, mu.vector, sd.vector, alpha.vector) {
  comp1.prod <- dnorm(y, mu.vector[1], sd.vector[1]) * alpha.vector[1]
  comp2.prod <- dnorm(y, mu.vector[2], sd.vector[2]) * alpha.vector[2]
  comp3.prod <- dnorm(y, mu.vector[3], sd.vector[3]) * alpha.vector[3]
  
  sum.of.comps <- comp1.prod + comp2.prod + comp3.prod
  comp1.post <- comp1.prod / sum.of.comps
  comp2.post <- comp2.prod / sum.of.comps
  comp3.post <- comp3.prod / sum.of.comps
  
  sum.of.comps.ln <- log(sum.of.comps, base = exp(1))
  sum.of.comps.ln.sum <- sum(sum.of.comps.ln)
  
  list("loglik" = sum.of.comps.ln.sum,
       "posterior.df" = cbind(comp1.post, comp2.post, comp3.post))
}

m_step <- function(y, posterior.df) {
  comp1.post <- posterior.df[, 1]
  comp2.post <- posterior.df[, 2]
  comp3.post <- posterior.df[, 3]
  
  comp1.mu<-weighted.mean(y,comp1.post)
  comp2.mu<-weighted.mean(y,comp2.post)
  comp3.mu<-weighted.mean(y,comp3.post)
  
  comp1.std<-sqrt(weighted.mean((y - comp1.mu)^2,comp1.post))
  comp2.std<-sqrt(weighted.mean((y - comp2.mu)^2,comp2.post))
  comp3.std<-sqrt(weighted.mean((y - comp3.mu)^2,comp3.post))
  
  comp1.alpha <- mean(comp1.post)
  comp2.alpha <- mean(comp2.post)
  comp3.alpha <- mean(comp3.post)
  
  list("mu" = c(comp1.mu, comp2.mu, comp3.mu),
       "std" = c(comp1.std, comp2.std, comp3.std),
       "alpha" = c(comp1.alpha, comp2.alpha, comp3.alpha))
}

for (i in 1:100) {
  if (i == 1) {
    # Initialization
    e.step <- e_step(y, y.summary.df[["mu"]], y.summary.df[["std"]],
                     y.summary.df[["alpha"]])
    m.step <- m_step(y, e.step[["posterior.df"]])
    cur.loglik <- e.step[["loglik"]]
    loglik.vector <- e.step[["loglik"]]
  } else {
    # Repeat E and M steps till convergence
    e.step <- e_step(y, m.step[["mu"]], m.step[["std"]], 
                     m.step[["alpha"]])
    m.step <- m_step(y, e.step[["posterior.df"]])
    loglik.vector <- c(loglik.vector, e.step[["loglik"]])
    
    loglik.diff <- abs((cur.loglik - e.step[["loglik"]]))
    if(loglik.diff < 1e-6) {
      break
    } else {
      cur.loglik <- e.step[["loglik"]]
    }
  }
}
loglik.vector

plot(loglik.vector)
m.step