from tkinter import *
import time

tk = Tk()
canvas = Canvas(tk, width = 800, height = 800)
canvas.pack()

scores = []
print("5개의 점수를 입력하세요.")
for k in range(5) :
    score = int(input("점수 입력 : "))
    scores.append(score)
i = 0
for score in scores :
    x1 = 100
    y1 = 100 + i
    x2 = 100 + score * 3
    y2 = 100 + 50 + i

    if score >= 90 :
        col = "green"
    elif score >= 80 and score < 90 :
        col = "blue"
    elif score >= 60 and score < 80 :
        col = "orange"
    else :
        col = "red"
    canvas.create_rectangle(x1, y1, x2, y2, fill = col)
    canvas.create_text(x2 + 40, y1 + 20, text = str(score))
    i = i + 100
    tk.update()
    time.sleep(0.5)
    
