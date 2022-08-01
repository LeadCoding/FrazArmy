def pwset(v):
    def helper(v, i, subSet, ans):
        
        # Our base case will hit when our i pointer reaches the end of given array v[]
        if i == len(v):
            ans.append(subSet.copy())
            return
        
        # we pick ith Element
        subSet.append(v[i])
        
        # We ask recursion to do rest of the task
        helper(v, i+1, subSet, ans)
        
        # Backtrack and Undo the change we have done
        subSet.pop()
        
        # We don't pick the ith element
        helper(v, i+1, subSet, ans)
    
    # varibles in pwset() scope
    ans = []
    subSet = []
    # Helper will store the ans in ans list        
    helper(v, 0, subSet, ans)
    return ans
