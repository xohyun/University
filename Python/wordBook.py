menu = 0
word_book = []

while menu != 4 :
    print("*************************************")
    print("*      Sookmyung Dictionary         *")
    print("*************************************")
    print("        1. Save words                ")
    print("        2. Delete words              ")
    print("        3. Print all words           ")
    print("        4. Exit                      ")
    print("=====================================")
    
    menu = int(input("Select >> "))

    if menu == 1 :
        print("Enter word to save. Press 'Enter' to finish\n")
        
        while True :
            word = input("Word : ")
            if len(word) == 0 :
                break
            if word in word_book :
                print("Aleady Exist")
                continue
            
            word_book.append(word)
    
    elif menu == 2 :
        print("Enter word to delete\n")
        
        while True :
            word = input("Word : ")
            if word not in word_book :
                print("No Exist")
                continue
            break

        word_book.remove(word)
        print("Deletion complete")
        
    elif menu == 3 :
        print("\n")
        for i in word_book :
            print(i)

    elif menu == 4 :
        break

    else :
        print("You entered wrong menu.")
