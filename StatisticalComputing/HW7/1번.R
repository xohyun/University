myfun1<-function(N)
{
  p <- 0
  for (n in 0:N) 
  {
    p <- 4*(-1)^n/(2 * n + 1) + p
  }
  return(p)
}

myfun2<-function(N)
{
  y <- 0:N
  sum((4*(-1)^y)/(2*y+1))
}

library(microbenchmark)
microbenchmark(myfun1(10000),myfun2(10000),unit="ms")

#myfun1(5)
#myfun2(5)

#x <- rep(c(1,-1), N/2)
