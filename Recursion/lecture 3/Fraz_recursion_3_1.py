def sum(n):
  if n==1:
    return 1
  else:
    partialAns = sum(n-1)
    return n+partialAns
# Take input from user
n=int(input())
print(sum(n))