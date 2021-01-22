import easygui

sentence = easygui.enterbox("Write a sentence")
easygui.msgbox('you wrote "%s"'% sentence)

choose = easygui.choicebox("Choose your word to study", choices = sentence.split())
easygui.msgbox("Today's word : \n%s"% choose)
