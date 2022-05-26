def powerSet(nums, i, res=[]):
    if(i < 0):
        if(res):
            print(*res)
        return

    res.append(nums[i])
    powerSet(nums, i-1, res)
    res.pop()
    while(i > 0 and nums[i] == nums[i-1]):
        i -= 1
    powerSet(nums, i-1, res)


nums = sorted(list(map(int, input().strip().split())))
powerSet(nums, len(nums)-1)
