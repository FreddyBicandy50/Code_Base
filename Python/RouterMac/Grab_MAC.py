def list_check(Word):
    #open our created lst file
    lst=open('lst.txt','r')
    
    for l in lst:
        #removeing new line from each word
        if len(l) == 12:
         temp = l[0:11]
         temp += ' '
         l = temp
        else:
            temp = l[0:12]
            temp += ' '
            l = temp
        if Word == l:  
            return True

def get_Mac():
    #open your cfg file from txt file 
    file=open("router.txt","r")  
    #list of founded mac adresses
    MAC=[]
    #creating the varabial strip to divid our words
    Strip=''
    #loop in each line in file
    for line in file:
        filterd_mac =line
        #replacing the = sign with white space
        filterd_mac= filterd_mac.replace('=', ' ')
        #striping the key word from start till whitespace reached means behind an equal sign
        for i in range(0,len(filterd_mac),1):
            if filterd_mac[i]!=' ':
                Strip+= filterd_mac[i]
            else: break  
        #add w space for increasing the strip lenght
        Strip+=' '
        if list_check(Strip)==True:  
            if len(filterd_mac)>=30:
                t = filterd_mac[0:12]
                t+='= '
                t += filterd_mac[12:29].upper()
                MAC.append(t)
        Strip='' 
    print(f"Black List MAC addess:")
    return MAC

#main func
if __name__=='__main__':
    #orginal word to used to reset @Modify
    Word="filter_mac"
    #index used for filter_mac# incremant number
    index=0
    #create and write txt file for our filter_mac number list 
    with open('lst.txt', 'w') as list:
        #generating list
        for i in range(20):
            Modify=Word
            Modify+=str(index)
            list.write(Modify)
            list.write('\n')
            index+=1 
    #call our function to fetch mac address
    MAC=get_Mac()
    for i in range(len(MAC)):
        print(MAC[i])
        