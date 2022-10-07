import random 

key = input("Press ENTER to flip a coin! Input anything else to quit! ")

Heads = 0
Tails = 0 

while (len(key) == 0):
    num = random.randint(0, 1)

    if num == 0:
        print("HEADS!") 
        Heads = Heads + 1
        print("Heads: " + str(Heads) + " Tails: " + str(Tails))
        key = input("Press ENTER to flip again! Input anything else to quit! ")
        print(" ") 
    else:
        print("TAILS!") 
        Tails = Tails + 1
        print("Heads: " + str(Heads) + " Tails: " + str(Tails))
        key = input("Press ENTER to flip again! Input anything else to quit! ")   
        print(" ") 

if len(key) != 0:
    print("Goodbye! Thanks for using Flipper!") 

