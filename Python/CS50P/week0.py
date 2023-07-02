#Indoor Voice
def indoorvoice():
    print(input("").lower())


#Playback Speed
def playbackspeed(): 
    print(input("").replace(" ","..."))

#Making Faces
def makingfaces(): 
    print(convert(input("").split(" ") ))

def convert(message="Hello",icon=":)"):
    if(iconemote==":)"):iconemote="🙂"
    elif (iconemote==":("): iconemote="🥺" 
    return message+" "+iconemote
makingfaces()