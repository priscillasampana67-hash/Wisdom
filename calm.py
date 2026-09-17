#x = "Python is awesome"
#print(x)

#x = "Python"
#y = "is"
#z = "awesome"
#print(x, y, z)
#print(x + y +  z)

x = 5
y = 10
print(x , y)

"""
def myFunc():
    print("Hello!")
    print("Welcome to Python!")
myFunc()

x = "awesome"

def myFunc():
    print("Python is " + x)
myFunc()
"""


x = "awesome"

def myFunc():
   global x
   x = "fantastic"
print("Python is " + x)

myFunc()

print("Python is " + x)