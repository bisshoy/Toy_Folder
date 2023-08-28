# completed on January 23, 2021 

# operations
def multiply (x, y):
    return x*y
def divide (x, y):
    return x/y
def add (x, y):
    return x+y
def subtract (x, y):
    return x-y

# inputs 
a = float(input("First number: "))
operation = input("What operation? * or / or + or -: ")
b = float(input("Second number: "))

# outputs 
while True:
    if operation in ("*", "/", "+", "-"):
        if operation == "*":
            print(a, "*", b, "=", multiply(a, b))
        elif operation == "/":
            print(a, "/", b, "=", divide(a, b))
        elif operation == "+":
            print(a, "+", b, "=", add(a, b))
        elif operation == "-":
            print(a, "-", b, "=", subtract(a, b))
        break
    else:
        print("Something's not right.")
        break
input("Press ENTER to exit") 
