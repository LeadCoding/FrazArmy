def reverseArrayHelper(nums, l, r):
    if(l >= r): return
    nums[r], nums[l] = nums[l], nums[r]
    return reverseArrayHelper(nums, l+1, r-1)

def reverseArray(nums):
    return reverseArrayHelper(nums, 0, len(nums)-1)

nums = list(map(int, input("Enter space seperated values : ").split()))
reverseArray(nums)
print(nums)