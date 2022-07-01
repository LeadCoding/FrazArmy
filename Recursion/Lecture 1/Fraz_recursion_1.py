# Factorial of a number using recursion

def factorial(n):
   if n == 0:
       return 1
   else:
       return n*factorial(n-1)


n=input();
if int(n) < 0:
   print("Error")
else:
   print(factorial(int(n)))
