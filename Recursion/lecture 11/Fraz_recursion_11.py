from typing import *

def rec(idx: int, n: int, k: int, cur: List[int], ans: List[List[int]]):
    if k > (n - idx + 1):
        return
    if k == 0:
        ans.append(cur)
        return
    rec(idx + 1, n, k, cur, ans)
    rec(idx + 1, n, k - 1, cur + [idx], ans)

def combinations(n: int, k: int) -> List[List[int]]:
    ans = []
    cur = []
    rec(1, n, k, cur, ans)
    return ans