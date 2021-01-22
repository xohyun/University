par(mfrow=c(2,2))

for (i in 2:5) {
  Profit <- function(n){
    X <- c(0:n)
    prob=dbinom(X,n,0.95)
    p <- X*1+(-i)*(X-100)*(X>100)
    return (sum(p * prob))
  }
  
  draw <- function() {
    result <- sapply(num_people, Profit)
    plot(num_people, result, xlim=c(100,110), ylim = c(80, 100), type = "o", xlab = "# of people",  ylab = "expectation of profit")
    points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")
    abline(h = 95, lty = 2, col = "blue")
  }
  
  draw()
  title(main = paste("비용이 ", i, "만원 일 때 수익의 기댓값 그래프"))
}