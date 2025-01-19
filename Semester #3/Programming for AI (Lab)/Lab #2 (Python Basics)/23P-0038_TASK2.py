import random

def take_choice():
    print("Which direction do you want to go?")
    choice=input("Enter up, right, left, or down: ").lower()
    return choice

def opt_evaluation_R1(choice, points):
    if choice=="up":
        print("Congrats, you have gained 2 points!")
        points+=2
    elif choice=="down":
        print("No difference to your points.")
    elif choice=="left":
        print("You gained 1 point!")
        points+=1
    elif choice=="right":
        print("Oops! You lost 1 point.")
        points-=1
    else:
        print("Invalid choice.")
    return points

def respawn():
    room=random.choice([1,2,3])
    print(f"\nYou have been respawned in Room {room}.")
    return room

def gameplay():
    print("You have entered a haunted mansion.")
    print("How to play?\nYou need to gain points by making wise choices.")
    print("You need at least 4 points in 3 turns to escape each room.")
    print("If you fail, you will be respawned in a random room.")

    room_number=1
    points=0
    turns=0
    min_points_to_escape=4

    print(f"\nYou started from Room {room_number}. Best of luck!")

    while 1:
        while turns<3:
            print(f"\nRoom {room_number}:")
            print(f"Your current points: {points}")
            choice=take_choice()
            points=opt_evaluation_R1(choice,points)
            turns+=1

        if points>=min_points_to_escape:
            print("\nCongratulations! You have escaped the room.")
            room_number+=1
            points=0
            turns=0
            print(f"\nYou have moved to Room {room_number}.")
            
        else:
            print("\nA ghostly figure emerges and attacks you! You have died.")
            room_number=respawn()
            points=0
            turns=0

gameplay()
