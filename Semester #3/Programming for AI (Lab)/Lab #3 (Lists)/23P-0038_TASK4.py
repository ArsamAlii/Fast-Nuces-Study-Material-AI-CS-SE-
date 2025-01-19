import random
from datetime import date

def date_func(dateexpire):
    currentdate=(2023,9,15) 

    if currentdate<dateexpire:
        return True
    else:
        return False

list1=["milk","bread","eggs","yogurt","cheese"]
list2=[(2023,9,30),(2023,10,15),(2023,9,25),(2023,9,8),(2023,10,10)]

zippedlist=list(zip(list1,list2))
#print(list(zippedlist))

filtered=filter(lambda x:date_func(x[1]),zippedlist)

print(list(filtered))
