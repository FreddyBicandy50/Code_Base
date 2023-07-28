#Fuel Gauge
def fuelcheck():
    print(FuelGauge("Fraction:"))



def FuelGauge(prompt):
    while True:
        try:
            fraction=input(prompt)
            x,y=fraction.split("/")
            res=(int(x)/int(y))*100
            if(res>=99):
                return 'F'
            elif(res<=1):
                return 'E'
            else:
                return res
        except ValueError:
            pass
        except ZeroDivisionError:
            pass



