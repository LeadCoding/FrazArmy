from copy import copy

def solve(result, currIndex, currSum, currList, B, ARR):

    if currSum == B:
        result.append(copy(currList))
        return

    if currIndex == len(ARR):
        return 

    solve(result, currIndex + 1, currSum, currList, B, ARR)


    count = 0

    while currSum <= B:

        count += 1

        currSum += ARR[currIndex]

        currList.append(ARR[currIndex])

        solve(result, currIndex + 1, currSum, currList, B, ARR)
    while count:
        currList.pop()
        count -= 1


def combSum(ARR, B):

    ARR.sort()
    
    result = []
    currList = []

    solve(result, 0, 0, currList, B, ARR)

    return result