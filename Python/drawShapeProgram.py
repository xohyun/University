import easygui
import turtle

turtle.setup(width = 550, height = 400)
t = turtle.Pen()
t.up()
t.backward(220)
t.down()

radius = 20
length = 30

select = easygui.buttonbox("Select shape", choices = ['circle', 'triangle'])
if select == 'circle' :
    number = int(easygui.enterbox("Enter number of circle to draw"))
   
    for i in range(number) :
        t.circle(radius)
        t.up()
        t.forward(2 * radius)
        t.down()
        if i % 2 == 1 :
            t.up()
            t.forward(radius)
            t.down()

else :
    number = int(easygui.enterbox("Enter number of triangle to draw"))
    for i in range(number) :
        for j in range(3) :
           t.forward(length)
           t.left(120)

        t.up()
        if i % 2 == 0 :
            t.forward(2 * length)
        else :
            t.forward(length)
        t.down()
