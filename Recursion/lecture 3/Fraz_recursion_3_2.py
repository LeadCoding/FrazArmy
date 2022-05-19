def fibo(n):
  if n==1:
    return 1
  if(n==2):
    return 1
  else:
    partialAns1 = fibo(n-1)
    partialAns2 = fibo(n-2)
    return partialAns1+partialAns2
# Take input from user
n=int(input())
print(fibo(n))