def perm(pos, str, ans):
    if pos>=len(str):
        ans.append(str)
    i = pos
    while i<len(str):
        str[i],str[pos]=str[pos],str[i]
        perm(pos+1,str,ans)
        str[i],str[pos]=str[pos],str[i] #backtracking
        i += 1

def generatePermutations(str):
    ans = []
    perm(0, str, ans)
    ans.sort()
    return ans
