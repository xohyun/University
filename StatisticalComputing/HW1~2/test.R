par(mfrow = c(2,2))

rep_num <- 100000
num_people <- 100:110

for(cost in 2:5) {
  profit <- function(n) {
    X <- rbinom(rep_num, n, 0.95)
    return(mean(X*1 + (-cost)*(X-100)*(X>100)))
  }
  result <- sapply(num_people, profit)
  plot(num_people, result, xlim=c(100,110), ylim = c(80, 100), type = "o", xlab = "# of people",  ylab = "expectation of profit")
  points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")
  abline(h = 95, lty = 2, col = "blue")
  title(main = paste("비용이 ", cost, "만원 일 때 수익의 기댓값 그래프"))
}