first=input("Enter first number :")
operator=input("Enter operator(+,-,*,/,%):")
second=input("Enter second number :")

first=float(first)
second=float(second)

if operator == '+':
    print(first+second)
elif operator == '-':
    print(first-second)
elif operator == '*':
    print(first*second)
elif operator == '/':
    print(first/second)
elif operator == '%':
    print(first%second)
else:
    print("Invalid operation!")