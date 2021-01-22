import turtle
turtle.setup(width = 600, height =600)

t = turtle.Pen()
color = ["green", "blue", "red", "yellow"] 
n = 100 #원의 반지름 길이

for i in color :
    t.color(i)
    t.begin_fill()
    t.forward(n)

    t.right(-90)
    t.circle(n, 90)
    t.left(90)
    t.forward(n)
    t.right(180)

    t.end_fill()


t.width(5)
t.pencolor("white")
t.right(90)
t.circle(n/2)

t.right(180)
t.circle(n/2)
