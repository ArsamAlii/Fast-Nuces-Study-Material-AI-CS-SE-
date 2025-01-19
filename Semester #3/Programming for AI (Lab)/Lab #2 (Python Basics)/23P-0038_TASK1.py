num=int(input("enter a num bw 1-10 : "))
if num>0:
    t_sum=0
    for i in range(1,num+1):
        t_sum=t_sum+i

    print(f"the sum of integers from 1 to {num} is {t_sum}")
    
else:
    print("pls enter positive integer only")
