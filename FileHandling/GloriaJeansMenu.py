!pip install prettytable
from prettytable import PrettyTable
import os
# MAIN MENU LIST
main_menu = ['ESPRESSO AND MOCHA CHILLERS','OVER ICE','CHOCOLATE CHILLERS','FUSION']
# SUB MENU ITEMS IN NESTED DICTIONARIES
espresso = {
    'VERY VANILA CHILLER':{
        "small":361,
        "regular": 409,
    },
    'COCOA LOCO':{
        "small":361,
        "regular": 409,
    },
    'COOKIES IT CREAM':{
        "small":361,
        "regular": 409,
    },
    'HAZELNUT MOCHA CHILLER':{
        "small":396,
        "regular": 461,
    },
    'CHOCOLATE MACADANIA CHILLER':{
        "small":396,
        "regular": 461,
    },
    'ITALIAN DOUCE CHILLER':{
        "small":396,
        "regular": 461,
    },
    'TIRAMSU CHILLER':{
        "small":399,
        "regular": 509,
    },
    'TOFFEE NUT CHILLER':{
        "small":399,
        "regular": 509,
    },
}
# SUB MENU ITEMS IN NESTED DICTIONARIES
overIce={
    "SIGNATURE ICE COFFEE":{
        "small":300,
        "regular": 374,
    },
    "ICED MOCHA":{
        "small":300,
        "regular": 361,
    },
    "ICE CARAMEL LATTE":{
        "small":378,
        "regular": 430,
    },
    "ICED AMERICANO":{
        "small":252,
        "regular": 274,
    },
    "BLUE BERRY LAMINADE":{
        "small":250,
        "regular": 291,
    },
    "LEYCHEE LAMINADE":{
        "small":250,
        "regular": 291,
    },
    "GREEN APPLE LAMONADE":{
        "small":250,
        "regular": 291,
    },
    "PEACH LAMONADE":{
        "small":250,
        "regular": 291,
    },
    "APPLE SODA":{
        "small":335,
        "regular": 348,
    },
    "LIME SODA":{
        "small":335,
        "regular": 361,
    },
    "ICED TEAS(peach/lemon leychee)*":{
        "small":339,
        "regular": 391,
    },
}
# SUB MENU ITEMS IN NESTED DICTIONARIES
chocolateChiller={
    'ORIGNAL ICED CHOCOLATE':{
        "small":348,
        "regular": 365,
    },
    'WHITE ICED CHOCOLATE':{
        "small":348,
        "regular": 365,
    },
    "CHOCOLATE DELIGHT":{
        "small":348,
        "regular": 400,
    },
}
# SUB MENU ITEMS IN NESTED DICTIONARIES
fusion ={
    "ICED LIME":{
        "small":335,
        "regular": 365,
    },
    "APPLE CHILLER":{
        "small":335,
        "regular": 365,
    },
    "CHAY CHILLER":{
        "small":348,
        "regular": 400,
    },
    "GREEN TEA CHILLER":{
        "small":348,
        "regular": 400,
    },
}

# FUNCTION FOR SOME DECENT PRINTINGS
def symbol(s,n,t,n_l=''):
    return '\t'*t+s*n+n_l
# FUNCTION FOR SOME DECENT PRINTINGS
def string(s,t,n_l=''):
    return '\t'*t+s+n_l

# FUNCTION FOR THE WELCOME
def welcome():
    print(symbol('*',24,6,'\n'),string('WELCOME TO GLORIA JEANS',6,'\n'),symbol('*',24,6,'\n'))
    print(symbol('-',25,2,'\n'),string('WHAT DO YOU WANT TO ORDER',2),'\n',symbol('-',25,2,'\n'))
# FUNCTION FOR PRINTING THE MENU
def printMenu():
    myTable = PrettyTable()  # IMPORTED LIBRARY CONSTRUCTOR AND CLASSES FOR DECENT TABLE PRINTING
    myTable.field_names = ["OPTION", "ITEM"]
    no = 0
    for i in main_menu: # PRINTING THE MAIN MENU ITEMS
        no += 1
        myTable.add_row([str(no), i])
    print(myTable)

def homeScreen(): # FUNCTION FOR THE MAIN SCREEN
    welcome()
    printMenu()

def Continue(): # FUNCTION TO RE ORDER
    global totalBill # GLOBAL VARYABLE FOR TOTAL BIL
    total = PrettyTable() # PRINTING TABLE USING LIBRARY
    print()
    choice_end = input('DO YOU WANT TO CONTINUE? => ').upper()
    if choice_end == 'N':
        os.system('cls')
        print()
        print(symbol('-',15,3,'\n'),string('YOUR TOTAL BILL',3,'\n'),symbol('-',15,3,'\n'))
        print(billTable) # PRINTING BILL
        total.field_names =["ITEM BILL", "TAX(15%)",'SERVICE CHARGES(10%)',"TOTAL BILL"]
        # BILL CALCULATIONS
        t = round((15/100)*totalBill,2)
        s = round((10/100)*totalBill,2)
        tb = round(t+s+totalBill,2)
        total.add_row([totalBill,t,s,tb]) # ADDING BILL INTO THE PRINTING TABLE
        print(total)
        with open('bill.txt','w') as bill:
            bill.write(str(billTable))
            bill.write('\n\n')
            bill.write(str(total))
    elif choice_end == 'Y':
        os.system('cls')
        print()
        main() # GOING BACK TO THE MAIN MENU

def displayChoise(data,name): # FUNCTION TO DISPLAY THE SUB MENU(TKING SUB MENU DICTIONARY AS PERAMETER)
    os.system('cls')
    print()
    global totalBill
    my_table = PrettyTable() # IMPORTED LIBRARY CONSTRUCTOR AND CLASSES FOR DECENT TABLE PRINTING
    my_table.field_names = ["OPTION", name, "SMALL", "REGULAR"] 
    num = 1
    itemList = []
    
    for i in data:
        item =[i, data[i]["small"], data[i]["regular"]] # ITEM IN THE LIST ALONG WITH THEIR PRICES
        itemList.append(item) # ADDING THE TOTAL ITEMS AND PRICES IN A SEPERATE LIST FOR FURTHER USE
        my_table.add_row([str(num), i, data[i]["small"], data[i]["regular"]]) # PUSHINH THE DATA INTO THE PRINTING TABLE
        num += 1
        
    print(my_table)
    print()
    main_choice = input('ENTER YOUR CHOICE (e.g. 1 S or 2 R) => ').upper() # DECING THE CHOICE OF USER
    main_choice = main_choice.split(" ") # SPLITING THE CHOICE FOR FURTHER USE
    try: # USING TRY EXCEPT FOR HANDLING THE ERROR
        option, size = main_choice[0], main_choice[1]
        for i in range(len(itemList)): # LOOP FOR PRINTING THE BILL ACORFING TO THE CHOICES OF USER
            if i == (int(option) - 1):
                if size == "S":
                    billTable.add_row([itemList[i][0],"SMALL",itemList[i][1]])
                    totalBill += itemList[i][1] # CALCULATING THE BILL
                    Continue() # REPEATING THE PROCESS
                elif size == "R":
                    billTable.add_row([itemList[i][0],"REGULAR",itemList[i][2]])
                    totalBill += itemList[i][2] # CALCULATING THE BILL
                    Continue() # REPEATING THE PROCESS
                else:
                    print(symbol('-',16,3,'\n'),string('ITEM SIZE ERROR!',3,'\n'),symbol('-',16,3,'\n')) # ERROR FOR WRONG ENTRY
                    Continue() # REPEATING THE PROCESS
    except: # ERROR FOR WRONG ENTRY
        print(symbol('-',17,3,'\n'),string('ITEM CHOICE ERROR',3,'\n'),symbol('-',17,3,'\n'))
        Continue() # REPEATING THE PROCESS
    

    

def main(): # MAIN FUNCTION FOR MAIN MENU

    while True:
        homeScreen() # DISPLAY
        print(symbol('-',24,0))
        main_choice = input('ENTER YOUR CHOICE => ') # CHOICES OF MAIN MENU
        print(symbol('-',24,0,'\n'))
        # SITUATION RUN ACORDING TO THE CHOICE
        if main_choice == '1':
            displayChoise(espresso, main_menu[0]) # FIRST ARGUMENT FOR THE MENU CHOICE, SECOND ARGUMENT FOR THE CHOICE DISPALY
        elif main_choice == '2':
            displayChoise(overIce, main_menu[1])
        elif main_choice == '3':
            displayChoise(chocolateChiller,main_menu[2])
        elif main_choice == '4':
            displayChoise(fusion,main_menu[3])
        else:
            os.system('cls')
            print()
            main()
        break
billTable = PrettyTable()  # IMPORTED LIBRARY CONSTRUCTOR AND CLASSES FOR DECENT TABLE PRINTING 
totalBill = 0
billTable.field_names =["ITEM", "SIZE","PRICE"]
print()
main() # CALLING THE FINAL FUNCTION
