def payment(category):
    if category=="Chocolate":
        return 1
    elif category=="Chips&crackers":
        return 2
    elif category=="Wafers":
        return 1.5
    else:
        return 2.5

def calc(price): 
    print("please pay",price,"$")
    pay=int(input("Payment:"))

    if pay<price:
        print("Not enough ammount of money")
    elif pay>price:
        print("Thank you here's your change",pay-price,"$")
    else:
        print("Thank you")