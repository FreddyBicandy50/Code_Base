#camel Case
def fetch(camelcase):
    snake=""
    for letter in camelcase:
        if(letter.isupper()):
           snake+="_"
           snake+=letter.lower()
        else: 
           snake+=letter.lower()
    return snake
def camelCase():
    print(f"snake_case:{fetch(input('CameclCase:'))}")
 
#Coke Machine
def insertcoin(Coin,amount):  
    if Coin==5 or Coin==10 or Coin==25:
        return amount - Coin
    else: 
        return amount
def CokeMachine():
     amount=50 
     while(amount>0):
        print("amount due:",amount)
        amount=insertcoin(int(input("insert Coin:")),amount)  
     print("change own:",amount*-1)

#Just setting up my twttr
def setting(inpt): 
    temp=""
    for vowel in inpt:
        if(vowel=='a' or vowel=='e' or vowel=='i' or vowel=='o' or vowel=='u'): 
           continue
        else: 
           temp+=vowel
    return temp
def twttr():
    print(f"Output:{setting(input('Input:').lower())}")
twttr() 