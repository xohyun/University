cup = {}
menu = {"Americano" : 1800, "Cafe latte" : 2200, "Cafe Mocha" : 2800}
choose = 0
pay = 0
total = 0
def print_menu() :
    print("=======Sookmyung Cafe=======")
    print("1. Select coffee menu")
    print("2. Check your order")
    print("3. Pay total price")
    print("4. Get change")
    print()

def print_coffeeMenu() :
    print("\n[Cafe Menu]")
    for m, value in menu.items() :
        print(" "+ m + " " + str(value) + "won")
    print("\n")

def select_menu() :
    while True :
        m = input("Select Menu : ")
        if m not in menu.keys():
            print("You selected wrong menu..")
            continue
        number = int(input("How many cups ? "))
        if m in cup.keys() :
            cup[m] += number
        else :
            cup[m] = number
        break
    
def check_order() :
    for menu, number in cup.items() :
        print(menu, "\t", number, "cups")

def calculate_price() :
    global pay, total
    total = 0
    for i in cup.keys() :
        for j in menu.keys() :
            if i == j :
                total += menu[j] * cup[i]
    print("TotalPrice : %d"%total)

    while True :
        pay = int(input("Pay money : "))
        if pay < total :
            print("Too small..\n")
            continue
        break

def get_change() :
    global pay, total
    change = pay - total
    print("Your change is %d won."%change)
    print("===========================")    

    print("5000 won : %d" % (change // 5000))
    change = change % 5000
    print("1000 won : %d" % (change // 1000))
    change = change % 1000
    print("500 won : %d" % (change // 500))
    change = change % 500
    print("100 won : %d" % (change // 100))
    change = change % 100

while choose != 4 :
    print_menu()
    choose = int(input("choose : "))

    if choose == 1 :
        print_coffeeMenu()
        select_menu()

    elif choose == 2 :
        check_order()

    elif choose == 3 :
        calculate_price()

    elif choose == 4 :
        get_change()
        print("\nThank you for using our machine")
        break
    else :
        print("Choose 1~4")
    print()
