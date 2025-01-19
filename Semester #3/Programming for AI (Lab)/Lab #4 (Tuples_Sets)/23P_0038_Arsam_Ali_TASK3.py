empty_set=set()

empty_set.add(1)
empty_set.add(3)
empty_set.add(5)
empty_set.add(7)

print(empty_set)


exists= 3 in empty_set
print("to check if exists : ",exists)

print("orignal empty set : ",empty_set)
empty_set.remove(5)
print("updated empty set : ",empty_set)