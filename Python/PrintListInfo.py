number = []

while True :
    print("Enter numbers. (To finish press 'Enter' key)")
    n = input()
    if len(n) == 0 :
        break
    number.append(float(n))

number.sort()
number_len = len(number)

sum = 0
for i in number :
    sum += i

number_center = int(number_len/2)
if number_len % 2 == 0 :
    center = (number[number_center-1] + number[number_center])/2
else :
    center = number[number_center]

print("You entered")
print(number)
print("sum : %.2f"% sum)
print("median : %.2f"% center)
print("average : %.2f"% (sum / number_len))
