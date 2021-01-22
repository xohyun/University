import easygui

total = 0
menu = 0

easygui.msgbox("Welcome to buy lunch ticket!\n(Lunch : 11:00 ~ 15:00)")

while menu != 'Exit' :
    menu = easygui.buttonbox("Choose lunch menu to buy", choices = ['Korean dish', 'Western dish', 'Chinese\'s style', 'Japanese', 'Exit'])

    if menu == 'Korean dish' :
        answer = int(easygui.enterbox("Korean dish is 2500 won.\nHow many tickets do you want to buy?"))
        total += 2500 * answer
    elif menu == 'Western dish' :
        answer = int(easygui.enterbox("Werstern dish is 3000 won.\nHow many tickets do you want to buy?"))
        total += 3000 * answer
    elif menu == 'Chinese\'s style' :
        answer = int(easygui.enterbox("Chinese food is 2000 won.\nHow many tickets do you want to buy?"))
        total += 2000 * answer
    elif menu == 'Japanese' :
        answer = int(easygui.enterbox("Japanese food is 3500 won.\nHow many tickets do you want to buy?"))
        total += 3500 * answer
    elif menu == 'Exit' :
        easygui.msgbox("Total amount to pay  : %d\nThanks for using!" % total)
    else :
        continue
