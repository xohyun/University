queue = []
menu = 0

while menu != 4 :
    print("********** Queue Program **********")
    print("1.Insert item to Queue")
    print("2.Delete item from Queue")
    print("3.Print Queue")
    print("4.Exit\n")
    
    menu = int(input("Enter menu : "))
    
    if menu == 1 :
        item = input("# Enter item to insert : ")
        queue.append(item)
        print("# \'%s\' is inserted."%queue[len(queue)-1])
        print("# State of Queue : ", end = "")
        print(queue)
        
    elif menu == 2 :
        if queue == [] :
            print("# Nothing to delete in queue.\n")
            continue
        
        item = queue[0]
        del queue[0]
        print("# First item \'%s\' was removed."%item)
        print("# State of Queue : ", end = "")
        print(queue)

    elif menu == 3 :
        if queue == [] :
            print("# Nothing in queue.\n")
            continue
        print("# State of Queue : ", end = "")
        print(queue)
    
    else :
        continue

    print()
