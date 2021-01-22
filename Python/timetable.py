dic = {}
menu = 0
class Lecture :
    def __init__(self, name, professor, limit, place) :
        self.name = name
        self.professor = professor
        self.limit = limit
        self.place = place
        
    def changeLimitOfStudent(self, limit) :
        self.limit = limit
    def changePlace(self, place) :
        self.place = place
    def printInfo(self) :
        print("Professor :", self.professor)
        print("Number of students :", self.limit)
        print("Place :", self.place)

while True :
    print("***********************************")
    print("              Time table           ")
    print("***********************************")
    print("   1. Open new class               ")
    print("   2. Change limit of students     ")
    print("   3. Change classroom             ")
    print("   4. Print lecture Info           ")
    print("   5. Exit                         ")
    print("***********************************")

    menu = int(input("Choose >> "))
    if menu == 1 :
        name = input("Lecture name : ")
        professor = input("Professor : ")
        limit = int(input("Limit of student : "))
        place = input("Place : ")

        lec = Lecture(name, professor, limit, place)
        dic[name] = lec

    elif menu == 2 :
        while True :
            name = input("Enter lecture name : ")
            if name in dic :
                break
        limit = int(input("Enter new limit of students : "))
        
        dic[name].changeLimitOfStudent(limit)

    elif menu == 3 :
        while True :
            name = input("Enter lecture name : ")
            if name in dic :
                break
        place = input("Enter new classroom: ")
        
        dic[name].changePlace(place)

    elif menu == 4 :
        name = input("Enter lecture name : ")
        dic[name].printInfo()
        
    elif menu == 5 :
        break

    else :
        continue
        
