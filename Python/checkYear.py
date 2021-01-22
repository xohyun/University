menu = 0
result = 0
day2020 = [31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31]
while menu != 3 :

    print("=====Checking Year Program=====")
    print("       1. Check Leap Year      ")
    print("       2. Check total day      ")
    print("       3.       Exit           ")
    print("===============================")
    menu = int(input("Select : "))
    if menu == 1 :
        year = int(input("Enter year to check : "))
        if (year % 4 == 0 and year % 100 != 0) or year % 400 == 0 :
            print("%d is leap year." % year)
        else :
            print("%d is not leap year." % year)
    elif menu == 2 :
        print("Enter month and date")
        month = int(input("Month : "))
        date = int(input("Date : "))
        for i in range(month - 1) :
            result += day2020[i]
        result += date
        print("2020.%d.%d is %dth day in 2020." % (month, date, result))
        result = 0
    elif menu == 3:
        print("Thanks for using program.")
    else :
        continue
