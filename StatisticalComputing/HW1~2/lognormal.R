rep_num<-100000
sigma<-1 # parameter of the lognormal distribution

s_size<-30 # sample size
s<-rlnorm(s_size*rep_num, meanlog = 0, sdlog = sigma)
sam_matrix<-matrix(s,s_size,rep_num)
s_mean<-apply(sam_matrix,2,mean) # sample means from the lognormal distribution

xgr<-seq(min(s_mean),max(s_mean),by=0.01)
nor_den<-dnorm(xgr,exp(sigma^2/2),sqrt((exp(sigma^2)-1)*(exp(sigma^2))/s_size))
plot(density(s_mean),ylim=c(0,max(nor_den)+0.5),main="CLT") # sampling distribution
abline(v=exp(sigma^2/2),col=2) # population mean 
lines(xgr,nor_den,col=4,lty=2) # approximation of the sampling distribution using CLT

par(mfrow=c(2,2))

s_size<-50 # sample size
s<-rlnorm(s_size*rep_num, meanlog = 0, sdlog = sigma)
sam_matrix<-matrix(s,s_size,rep_num)
s_mean<-apply(sam_matrix,2,mean) # sample means from the lognormal distribution

xgr<-seq(min(s_mean),max(s_mean),by=0.01)
nor_den<-dnorm(xgr,exp(sigma^2/2),sqrt((exp(sigma^2)-1)*(exp(sigma^2))/s_size))
plot(density(s_mean),ylim=c(0,max(nor_den)+0.5),main="CLT") # sampling distribution
abline(v=exp(sigma^2/2),col=2) # population mean 
lines(xgr,nor_den,col=4,lty=2) # approximation of the sampling distribution using CLT


s_size<-100 # sample size
s<-rlnorm(s_size*rep_num, meanlog = 0, sdlog = sigma)
sam_matrix<-matrix(s,s_size,rep_num)
s_mean<-apply(sam_matrix,2,mean) # sample means from the lognormal distribution

xgr<-seq(min(s_mean),max(s_mean),by=0.01)
nor_den<-dnorm(xgr,exp(sigma^2/2),sqrt((exp(sigma^2)-1)*(exp(sigma^2))/s_size))
plot(density(s_mean),ylim=c(0,max(nor_den)+0.5),main="CLT") # sampling distribution
abline(v=exp(sigma^2/2),col=2) # population mean 
lines(xgr,nor_den,col=4,lty=2) # approximation of the sampling distribution using CLT



s_size<-500 # sample size
s<-rlnorm(s_size*rep_num, meanlog = 0, sdlog = sigma)
sam_matrix<-matrix(s,s_size,rep_num)
s_mean<-apply(sam_matrix,2,mean) # sample means from the lognormal distribution

xgr<-seq(min(s_mean),max(s_mean),by=0.01)
nor_den<-dnorm(xgr,exp(sigma^2/2),sqrt((exp(sigma^2)-1)*(exp(sigma^2))/s_size))
plot(density(s_mean),ylim=c(0,max(nor_den)+0.5),main="CLT") # sampling distribution
abline(v=exp(sigma^2/2),col=2) # population mean 
lines(xgr,nor_den,col=4,lty=2) # approximation of the sampling distribution using CLT


s_size<-1000 # sample size
s<-rlnorm(s_size*rep_num, meanlog = 0, sdlog = sigma)
sam_matrix<-matrix(s,s_size,rep_num)
s_mean<-apply(sam_matrix,2,mean) # sample means from the lognormal distribution

xgr<-seq(min(s_mean),max(s_mean),by=0.01)
nor_den<-dnorm(xgr,exp(sigma^2/2),sqrt((exp(sigma^2)-1)*(exp(sigma^2))/s_size))
plot(density(s_mean),ylim=c(0,max(nor_den)+0.5),main="CLT") # sampling distribution
abline(v=exp(sigma^2/2),col=2) # population mean 
lines(xgr,nor_den,col=4,lty=2) # approximation of the sampling distribution using CLT
