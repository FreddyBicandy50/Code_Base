#Deep Thought 
def thought(answer):
    match answer:
        case "42" | "forty-two" | "Forty-two" | "Forty-Two"|"FORTY-two"|"forty-TWO":
            return "yes"
        case _:
            return "no"
def Deep_Thought():
    print(thought(input("What is the answer to the greate question of life, the universe, and everything ?")))


#Home Federal Savings Bank 
def greeting(greet):
    if greet=="hello": 
        return "0" 
    elif greet[0]=="h":
        return "20" 
    else : 
        return "100"  
def HFSB(): 
    print(f"${greeting(input('Greeting:').replace(' ','').lower())}")
 
 
#File Extensions
def extension(ext):
    print(ext)
    if ext=="":
        return "application/octet-stream"  
    elif ext=="gif" or ext=="jpg" or ext=="jpeg" or ext=="png": 
        return "image/"+ext 
    elif ext=="pdf" or ext=="txt" or ext=="zip":
        return "file/"+ext
    else :
        return "invalid file type"  

     
def FS(): 
    ext=""
    file=input('File name:').replace(' ','').lower().split('.') 
    ext = file[1] if len(file) > 1 else ''; 
    print(f"{extension(ext)}")
 

#Math Interpreter
def calc(exp): 
        if(exp.split("+")):
            exp=exp.split("+")
            if exp[0].isdigit() and exp[1].isdigit(): 
                return int(exp[0]) + int(exp[1])
            else:  
                return "Math error"
        if (exp.split("*")):
            exp=exp.split("*")
            if exp[0].isdigit() and exp[1].isdigit():
                return int(exp[0]) * int(exp[1])
            else:
                 return "Math error"
        if (exp.split("/")):
            exp=exp.split("/")
            print(f"{exp[0]}/{exp[1]}")
            if exp[0].isdigit() and exp[1].isdigit():
                return int(exp[0]) / int(exp[1])
            else:
                 return "Math error"
        if (exp.split("-")):
            exp=exp.split("-")
            if exp[0].isdigit() and exp[1].isdigit():
                return int(exp[0]) - int(exp[1])
            else:
                 return "Math error"
 
def MathInterpreter():
    print(f"{calc(input('Expression:'))}")
MathInterpreter()