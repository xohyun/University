par(mfrow = c(2,2))
Profit <- function(n, cost){
  print(cost)
  X <- c(0:n)
  prob=dbinom(X,n,0.95)
  p <- X*1+(-cost)*(X-100)*(X>100)
  return (sum(p * prob))
}

i <- 2
result <- sapply(num_people, Profit(,2))
plot(num_people, result, main=c("비용이 ", i, "만원 일 때 비용의 기댓값 그래프", sep = ""),xlim=c(100,110), ylim = c(86, ceiling(max(result))), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")


result <- sapply(num_people, Profit(num_people,3))
plot(num_people, result, main="비용이 3만원 일 때 비용의 기댓값 그래프",xlim=c(100,110), ylim = c(86, ceiling(max(result))), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")

result <- sapply(num_people, Profit(,4))
plot(num_people, result, main="비용이 4만원 일 때 비용의 기댓값 그래프",xlim=c(100,110), ylim = c(86, ceiling(max(result))), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")


result <- sapply(num_people, Profit(,5))
plot(num_people, result, main="비용이 5만원 일 때 비용의 기댓값 그래프",xlim=c(100,110), ylim = c(86, ceiling(max(result))), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")


#################
par(mfrow = c(2,2))
for (i in 2:5) {
  
}