def add(num1, num2):
    return num1 + num2
def subtract(num1, num2):
    return num1 - num2
def multiply(num1, num2):
    return num1 * num2
def divide(num1, num2):
    if num2 == 0:
        return "Error! Division by zero."
    return num1 / num2
num1=None#thiet lap num1 de chay dieu kien trong vong lap
total=0#thiet lap total de chay vong lap khong bi loi bien chua xac dinh
operation=None

print("calculator_ver1.0 by thieen")
print("enter number:")

while True:#True de vong lap chay lien tuc
    if num1 is None:
        num1=float(input())
        operation=input()
        num2=float(input())
    else:
        num1=total
        operation=input() 
        num2=float(input())  

    print("------------")

    if operation == '+':
        total=add(num1, num2)  #co the add ham vao bien 
    elif operation == '-':
        total=subtract(num1, num2)
    elif operation == '*':
        total=multiply(num1, num2)
    elif operation == '/':
        total=divide(num1, num2)
    else:
        print("Invalid operation!")# Simple calculator program      

    print(total)
