menu = 0
dic = {}
rank = []

while True :
    print("******************************************")
    print("*          Sookmyung Dictionary          *")
    print("******************************************")
    print("              1. Save words               ")
    print("              2. Delete words             ")
    print("              3. Print all words          ")
    print("              4. Search word              ")
    print("              5. Word Test                ")
    print("              6. Show Test score          ")
    print("              7. Exit                     ")
    print("==========================================")

    menu = int(input("Select >> "))
    
    if menu == 1 :
        print("Enter word to save. Press 'enter' to finish")

        while True :
            word = input("\nWord : ")
            if len(word) == 0 :
                break

            if word in dic :
                print("Already Exist")
                continue

            mean = input("Mean : ")
            dic[word] = mean
            
    elif menu == 2 :
        if dic == {} :
            print("No word in dictionary")
            continue
        print("Enter word to deleted\n")
        while True :
            word = input("Word : ")
            if word in dic :
                del dic[word]
                print("Deletion is completed")
                break

            else :
                print("No such words")
                
    elif menu == 3 :
        print("\n")
        for word in dic :
            print(word, "\t", dic[word], "\n")

    elif menu == 4 :
        print("Enter word to search\n")
        word = input("word : ")

        print("\n", word, "\t", dic[word])
        
    elif menu == 5 :
        if dic == {} :
            print("\nTest can't be started, because of no words")
            continue
            
        correct = 0
        for word in dic :
            print(word, " : ", end = "")
            answer = input()
            if answer == dic[word] :
                print("Correct!")
                correct = correct + 1
            else :
                print("Wrong..")
            print()

        print("You got %d answers." % correct)
        rank.append(correct)

    elif menu == 6 :
        counter = 1
        c = 0
        print("  ScoreBoard")
        print("==================")
        rank.sort(reverse = True)
        for i in range(len(rank)) :
            print("%d rank   %danswers" % (counter, rank[i]))
            if (i + 1) < len(rank) and rank[i] != rank[i + 1] :
                counter = counter + c + 1
                c = 0
            else :
                c = c + 1

    elif menu == 7 :
        print("Thanks for using dictionary")
        break
