import random
import easygui

name = easygui.enterbox("What is your name?")
easygui.msgbox("Ok, "+ name + "!\nLet's play 21 game")

computer = random.randint(1, 21)
person = random.randint(1, 13)

select = easygui.buttonbox("Your first card is "+ str(person) + "\nDo you want more?", choices = ['yes', 'no'])
if select == 'yes' :
    person2 = random.randint(1, 13)
    easygui.msgbox("Your second card is "+ str(person2) + "\nCheck your result")
    person = person + person2
else :
    easygui.msgbox("Ok, check your result")

result = str(person)
result_com = str(computer)

if person > 21 :
    easygui.msgbox("Your final result is "+ result + ". It is over 21, so you lose.\nComputer's card was "+ result_com)
elif person > computer :
    easygui.msgbox("Your final result is "+ result + "\nComputer's card was " + result_com + ".\nYou win!")
else :
    easygui.msgbox("Your final result is "+ result + "\nComputer's card was " + result_com + ".\nYou lose!")
