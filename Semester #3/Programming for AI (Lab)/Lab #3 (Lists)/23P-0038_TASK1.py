import random

#def recursive_ask():



def response_func(user_input):

    if user_input=="whats your name ":
        return "my name is python ai"
    
    elif user_input=="hows the weather":
        return "its rainy"
    
    elif user_input == "how are you":
        return "i am fine what about you"
    
    else:
        return "i am sorry i dont userstand you"
    
def chatbot():
    userinput=input("enter whatever you want (end to exit)")

    userinput.lower()

    if userinput=="end":
        print("thanks for using me byeee")

    else:
        response_func(userinput)
        print (response_func)



print("hello user you are welcome")
chatbot()
