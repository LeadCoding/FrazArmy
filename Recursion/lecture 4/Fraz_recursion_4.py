def Pow(X,N):
    if N == 0:
        return 1    
    temp = Pow(X,N//2)
    if(N%2 == 1):
        return temp* temp*X
    return temp * temp

x = int(input())
n = int(input())
print(Pow(x,n))