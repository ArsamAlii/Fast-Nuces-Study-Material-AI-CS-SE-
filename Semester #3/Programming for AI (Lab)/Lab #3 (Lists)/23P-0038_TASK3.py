import random

word_list=["Apple","Banana","Avocado","Cherry","Apricot","Grapes"]

count=0

for i in range (len(word_list)):
    x=word_list[i]
    if x[0]=='A':
     count+=1

print(count)