def helper(v,i,subSet,ans):
	if i == len(v):
		ans.append(subSet)
		return

	subSet.append(v[i])
	helper(v,i+1,subSet,ans)
	subSet.pop()
	helper(v,i+1,subSet,ans)

def pwset(v):
	ans = []
	subSet = []
	helper(v,0,subSet,ans)
	return ans
