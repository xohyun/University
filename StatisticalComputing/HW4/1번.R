library(boot)
set.seed(12345)
alpha <- 0.05
num_iter <- 2000
size <- c(25, 50, 100, 200, 400)

LCL1 <- UCL1 <- numeric(num_iter)
LCL2 <- UCL2 <- numeric(num_iter)
LCL3 <- UCL3 <- numeric(num_iter)
result1 <- result2 <- result3 <- numeric(length(size))

k <- 1
for (s in size) {
  counter1 <- counter2 <- counter3 <- 0
  
  for (j in 1:num_iter) {
    data <- rchisq(s, 2)
    
    boot_find <- function(x, ix) {
      var(x[ix])
    }
    
    boot.obj <- boot(data, R = 1000, statistic = boot_find)
    res <- boot.ci(boot.obj, type = c("basic", "perc"))
    
    LCL1[j] <- (s-1)*var(data)/qchisq(1-alpha/2, df = s-1); UCL1[j] <- (s-1)*var(data)/qchisq(alpha/2, df = s-1)
    LCL2[j] <- res$basic[,4]; UCL2[j] <- res$basic[,5]
    LCL3[j] <- res$percent[,4]; UCL3[j] <- res$percent[,5]
    
    if (LCL1[j] <= 4 & UCL1[j] >= 4) {counter1 = counter1 + 1}
    if (LCL2[j] <= 4 & UCL2[j] >= 4) {counter2 = counter2 + 1}
    if (LCL3[j] <= 4 & UCL3[j] >= 4) {counter3 = counter3 + 1}
  }
  result1[k] <- counter1 / num_iter
  result2[k] <- counter2 / num_iter
  result3[k] <- counter3 / num_iter
  k <- k + 1
}
result <- cbind(result1, result2, result3)
colnames(result) <- c("정규분포 기반", "Bootstrap(basic)", "Bootstrap(perc)")
rownames(result) <- size
result