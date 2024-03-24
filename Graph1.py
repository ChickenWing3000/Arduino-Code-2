from turtle import *
from tkinter import *

werte = input("Werte?")
str_leistungswerte = [werte]
str_leistungswerte = werte.split(",")
print("Konvertierte Liste:", str_leistungswerte)
print(len(str_leistungswerte))

zeitintervall = 1
energie = 0
hoehe = 300 # höhe...
laenge = 800 # ...und laenge veraenerbar!
maxzeit = 180
maxwatt = 0.1 # Unbedingt noch aendern !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
counter = 0
leistungswerte = []
rueckwaertsmultiplikator = 1000
wirkungsgrad = 0

while len(str_leistungswerte) > counter:
    werte = str_leistungswerte[counter]
    #print(werte)
    werte = int(werte)
    #print(werte)
    leistungswerte.append(werte)
    counter +=1
    #print(counter)

print(leistungswerte)

root = Tk()


shape("turtle")
# makeTurtle()
# hideturtle()

pencolor("black")
penup()
setpos(laenge/2*-1,hoehe)
pendown()
setpos(laenge/2*-1,0)
setpos(laenge/2,0)
showturtle()
setpos(laenge/2*-1,0)
pencolor("red")

counter = 0

for stelle in leistungswerte:
    counter += 1
    if stelle > 0:
        setpos(((laenge/maxzeit)*(counter))-400,(stelle/rueckwaertsmultiplikator)*(hoehe/maxwatt))
    else:
        setpos(((laenge/maxzeit)*(counter))-400,0)


for x in leistungswerte:
    energie += x * zeitintervall

wirkungsgrad = 238/energie*100
wirkungsgrad = int(wirkungsgrad)

print("Die freigesetzte Energie sind ", energie ," Joule!")
print("Der Wirkungsgrad im vergleich zur potentiellen Lageenergie ist ", wirkungsgrad ,"%")

root.mainloop()