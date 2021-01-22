library(ironslag)
library(DAAG)
attach(ironslag)

set.seed(12345)
n <- length(magnetic)
e1 <- e2 <- e3 <- e4 <- numeric(n)
yhat1 <- numeric(10)

for (k in 1:100) {
  test <- sample(1:n, 10)
  training <- setdiff(1:n, test)
  
  x <- chemical[-test]
  y <- magnetic[-test]
  
  J1 <- lm(y ~ x)
  yhat1 <- J1$coef[1] + J1$coef[2] * chemical[test]
  e1[k] <- mean((magnetic[test] - yhat1)^2)
  
  J2 <- lm(y ~ x + I(x^2))
  yhat2 <- J2$coef[1] + J2$coef[2] * chemical[test] + J2$coef[3] * chemical[test]^2
  e2[k] <- mean((magnetic[test] - yhat2)^2)
  
  J3 <- lm(log(y) ~ x)
  logyhat3 <- J3$coef[1] + J3$coef[2] * chemical[test]
  yhat3 <- exp(logyhat3)
  e3[k] <- mean((magnetic[test] - yhat3)^2)
  
  J4 <- lm(log(y) ~ log(x))
  logyhat4 <- J4$coef[1] + J4$coef[2] * log(chemical[test])
  yhat4 <- exp(logyhat4)
  e4[k] <- mean((magnetic[test] - yhat4)^2)
}
c(mean(e1), mean(e2), mean(e3), mean(e4))
