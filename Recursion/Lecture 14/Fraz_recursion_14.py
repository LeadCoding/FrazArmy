from copy import deepcopy
def help(i: int,K: int,N: int, temp: [], ans: [[]], last: int):
    if i == K:
        if N == 0:
            ans.append(deepcopy(temp))

    for curr in range(last + 1, 10):
        if N - curr < 0:
            break
        temp.append(curr)
        help(i + 1, K, N - curr, temp, ans, curr)
        temp.pop()


def combinationSum3(K: int, N: int) -> [[]]:
    ans = []
    temp = []
    help(0, K, N, temp, ans, 0)
    return ans
