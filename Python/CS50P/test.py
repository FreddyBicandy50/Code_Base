calc = "f*1"
if(calc.split("+")):
    operands = calc.split("+")
if(calc.split("*")):
    calc = calc.split("*")
    operands="*"

if(calc[0].isdigit()):
    print(calc[0]*2)
else:
    print("no") 