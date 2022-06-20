def combinationsHelper(digits, digToStr, j, temp, ans):

    if(j == len(digits)):
        ans.append(temp)
        return

    val = ord(digits[j]) - ord('0')

    for i in range(len(digToStr[val])):

        temp += digToStr[val][i]
        combinationsHelper(digits, digToStr, j + 1, temp, ans)
        temp = temp[:-1]


def combinations(s):

    digToStr = ["", "", "abc", "def", "ghi",
                    "jkl", "mno", "pqrs", "tuv", "wxyz"]

    n = len(s)
    temp = ""
    ans = []

    if(n == 0):
        return ans

    combinationsHelper(s, digToStr, 0, temp, ans)

    return ans
