def toString(List):
    return ''.join(List)

def permute(pos, strng, ans):
    if pos==ans:
        print (toString(strng))
    else:
        for i in range(pos,ans):
            strng[pos], strng[i] = strng[i], strng[pos]
            permute(pos+1,strng,ans)
            strng[pos], strng[i] = strng[i], strng[pos] # backtrack
 

string = input()
n = len(string)
a = list(string)
permute(0, a, n)