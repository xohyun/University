from tkinter import *
import time

tk = Tk()
canvas = Canvas(tk, width = 500, height = 500)
canvas.pack()
canvas.create_polygon(250, 400, 275, 450, 225, 450)
canvas.create_rectangle(225, 450, 275, 500, fill = "black")

y = 0
flag = True
while True :
    if flag == True : 
        canvas.move(1, 0, -35)
        canvas.move(2, 0, -35)
        if y == 10 :
            y = 0
            flag = False
    else :
        canvas.move(1, 0, 2)
        canvas.move(2, 0, 2)
        if y == 175:
            y = 0
            flag = True
    y += 1
        
    tk.update()
    time.sleep(0.05)
