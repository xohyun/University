B <- 1000
p <- 0.2
n <- c(25, 50, 100, 200)
alpha <- 0.05
res <- numeric(4)
p_store <- numeric(1000)

for (i in n) {
  btest <- function(m) {
    for (j in 1:m) {
      sigma <- sample(c(1,10), size = i, replace = TRUE, prob = c(1-p, p))
      data <- rnorm(n, 0, sigma)
      
      data_ext <- c(data - mean(data), mean(data) - data)
      counter <- 0
      
      for (b in 1:B) { 
        bdata <- sample(data_ext, size = i, replace = TRUE)
        
        f_r <- bdata - mean(bdata)
        f_l <- mean(bdata) - bdata
        
        ks <- ks.test(f_r, f_l)$p.value
        if (ks <= alpha) {counter = counter + 1}
      }
      
       p_store[j] <- counter / B
    }
    
    
  }
  #res[i] <- btest(1000)
  btest(1000)
}


####################
#Type 1 error를 추정
set.seed(12345)
B <- 1000
p <- 0.2
size <- c(25, 50, 100, 200)
bootstrap_type1error <- numeric(4)
k <- 1
alpha <- 0.05
num_iter <- 1000
test_res_bootstrap <- numeric(num_iter)

for (s in size) {
  for (i in 1:num_iter) {
    sigma <- sample(c(1, 10), size = s, replace = TRUE, prob = c(1-p, p))
    data <- rnorm(s, 0, sigma)
    v <- ks.test(data - mean(data), mean(data) - data)$statistic
    
    data_ext <- c(data, 2*mean(data)-data)
    counter <- 0
    
    for (b in 1:B) {
      bdata <- sample(data_ext, size = s, replace = TRUE)
      
      f_r <- bdata - mean(bdata)
      f_l <- mean(bdata) - bdata
      
      vstar <- ks.test(f_r, f_l)$statistic
      if (abs(vstar) >= abs(v)) {counter <- counter + 1}
    }
    pvalue <- counter/B
    test_res_bootstrap[i] <- as.integer(pvalue<alpha)
  }
  bootstrap_type1error[k] <- mean(test_res_bootstrap)
  k <- k + 1
}
bootstrap_type1error

#검정력 추정
set.seed(12345)
B <- 1000
p <- 0.2
size <- c(25, 50, 100, 200)
bootstrap_power <- numeric(4)
k <- 1
alpha <- 0.05
num_iter <- 1000
test_res_bootstrap <- numeric(num_iter)

for (s in size) {
  
  for (i in 1:num_iter) {
    data <- rexp(s)
    v <- ks.test(data - mean(data), mean(data) - data)$statistic
    
    data_ext <- c(data, 2*mean(data)-data)
    counter <- 0
    
    for (b in 1:B) {
      bdata <- sample(data_ext, size = s, replace = TRUE)
      f_r <- bdata - mean(bdata)
      f_l <- mean(bdata) - bdata
      vstar <- ks.test(f_r, f_l)$statistic
      if (abs(vstar) >= abs(v)) {counter <- counter + 1}
    }
    pvalue <- counter/B
    test_res_bootstrap[i] <- as.integer(pvalue<alpha)
  }
  bootstrap_power[k] <- mean(test_res_bootstrap)
  k <- k + 1
}
bootstrap_power