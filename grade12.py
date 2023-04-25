
Machine = {
  "chocolate=1": ["twix=2$","Galaxy=1$","snickers=1.5$","Adicto-1$"],
  "Soft Drink=2": ["Miranda=2$","7Up=2$","Pepsi=2$","Coca cola=2$"],
  "Chips=3": ["Master=1$","Snips=1$","Lays=2$","Pringles=3$"]
}

for key, values in Machine.items():
  print(key, values)
price=0
payment=0
if(int(input("enter the key number"))==3):
    print(Machine["Chips=3"])
    if(input("enter the key number")=="Pringles"):
        print(Machine["Chips=3"]["Pringles=3$"])
        price+=3
        payment=int(input("please pay the price above:"))
        calculate(payment)

