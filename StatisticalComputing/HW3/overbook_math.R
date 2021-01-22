n<-102
X<-c(0:n)
Profit<-X*1+(-2)*(X-100)*(X>100)
prob=dbinom(X,n,0.95) # P(X=i), i=0,1,2,....,n # dbinom : ���׺��� Ȯ�������Լ�

sum(Profit*prob)

##################
num_people <- c(100:110)
Profit <- function(n){
  X <- c(0:n)
  prob=dbinom(X,n,0.95)
  p <- X*1+(-2)*(X-100)*(X>100)
  return (sum(p * prob))
}

par(mfrow=c(2,2))

result <- sapply(num_people, Profit)
plot(num_people, result, main="����� 2���� �� �� ����� ��� �׷���",xlim=c(100,110), ylim = c(80, 100), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")
abline(h = 95, lty = 2, col = "blue")

Profit <- function(n){
  X <- c(0:n)
  prob=dbinom(X,n,0.95)
  p <- X*1+(-3)*(X-100)*(X>100)
  return (sum(p * prob))
}
result <- sapply(num_people, Profit)
plot(num_people, result, main="����� 3���� �� �� ����� ��� �׷���",xlim=c(100,110), ylim = c(80, 100), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")
abline(h = 95, lty = 2, col = "blue")


Profit <- function(n){
  X <- c(0:n)
  prob=dbinom(X,n,0.95)
  p <- X*1+(-4)*(X-100)*(X>100)
  return (sum(p * prob))
}
result <- sapply(num_people, Profit)
plot(num_people, result, main="����� 4���� �� �� ����� ��� �׷���",xlim=c(100,110), ylim = c(80, 100), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")
abline(h = 95, lty = 2, col = "blue")


Profit <- function(n){
  X <- c(0:n)
  prob=dbinom(X,n,0.95)
  p <- X*1+(-5)*(X-100)*(X>100)
  return (sum(p * prob))
}
result <- sapply(num_people, Profit)
plot(num_people, result, main="����� 5���� �� �� ����� ��� �׷���",xlim=c(100,110), ylim = c(80, 100), type = "o", xlab = "# of people",  ylab = "expectation of profit")
points(num_people[which(result == max(result))], max(result), pch = 15, col = "blue")
abline(h = 95, lty = 2, col = "blue")