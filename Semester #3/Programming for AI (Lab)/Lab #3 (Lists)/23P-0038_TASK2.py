import random

def take_choice():
    print("\nWhich direction do you want to go?")
    choice=input("Enter up, right, left, or down: ").lower()
    return choice

def opt_evaluation(choice, points, inventory):
    if choice == "up":
        print("you found a hidden path and gained 2 points!")
        points += 2
        item_found=random.choice(["Magic Stone","Ancient Scroll","Healing Potion"])
        inventory.append(item_found)
        print(f"You found a {item_found} and added it to your inventory.")
    elif choice=="down":
        print("You stumbled upon a calm stream. No change in points.")
    elif choice=="left":
        print("You discovered an abandoned cabin and gained 1 point!")
        points+=1
    elif choice=="right":
        print("A wild animal startled you! You lost 1 point.")
        points-=1
    else:
        print("Invalid choice.")
    return points, inventory

def manage_inventory(inventory):
    print("\nYour current inventory:", inventory)
    action=input("Do you want to 'add', 'remove', or 'access' an item? ").lower()
    
    if action=="add":
        item=input("Enter the item you want to add: ")
        inventory.append(item)
        print(f"{item} has been added to your inventory.")
        
    elif action=="remove":
        item=input("Enter the item you want to remove: ")
        if item in inventory:
            inventory.remove(item)
            print(f"{item} has been removed from your inventory.")
        else:
            print(f"{item} is not in your inventory.")
            
    elif action=="access":
        item=input("Enter the item you want to access: ")
        if item in inventory:
            print(f"You access the {item}. It's useful!")
        else:
            print(f"{item} is not in your inventory.")
    
    else:
        print("Invalid action.")
    
    return inventory

def respawn():
    location=random.choice(["Enchanted Grove", "Ancient Ruins", "Dark Cave"])
    print(f"\nYou have been respawned in the {location}.")
    return location

def gameplay():
    print("You have entered a mysterious forest.")
    print("How to play?\nMake wise choices to gain points and manage your inventory to survive.")
    print("You need at least 4 points in 3 turns to move deeper into the forest.")
    print("If you fail,you will be respawned to a new location.")

    location="Forest Entrance"
    points=0
    turns=0
    min_points_to_progress=4
    inventory=["axe","compass","torch"]

    print(f"\nYou started at the {location}. Best of luck!")

    while True:
        while turns<3:
            print(f"\nCurrent Location: {location}")
            print(f"Your current points: {points}")
            choice=take_choice()
            points,inventory=opt_evaluation(choice, points, inventory)
            turns+= 1
            
            manage_inventory(inventory)

        if points>=min_points_to_progress:
            print("\nCongratulations! You have navigated deeper into the forest.")
            location=random.choice(["Mystic River", "Haunted Grove", "Twilight Clearing"])
            points=0
            turns=0
            print(f"\nYou have moved to the {location}.")
            
        else:
            print("\nA shadowy figure appears and you are lost in the woods!")
            location=respawn()
            points=0
            turns=0

gameplay()
