from imad_and_matteo import * 
from heinz_and_theo import *
from jana_and_nathalia import * 
price=0
while(True):
    machine=print_machine() 
    category=select_category(machine)  
    if(category!=False):
        price+=payment(category)
    else:
        print("INVALID")
    print("Do you need to add new item?")
    answer=input("[Y/N]:")
    if (answer=="N" or answer=="n"):
        break

calc(price)