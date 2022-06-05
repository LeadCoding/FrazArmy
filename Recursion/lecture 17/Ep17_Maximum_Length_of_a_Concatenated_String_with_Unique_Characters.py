# Approach 1 --
def dfs(strings, currString, position):
    st = set()

    for ch in currString:
        st.add(ch)

    if (len(st) != len(currString)):
        return 0

    res = len(currString)

    for currPos in range(position, len(strings)):
        string = strings[currPos]
        res = max(res, dfs(strings, string+currString, currPos + 1))

    return res

def stringConcatenation(arr):

    string = ""
    return dfs(arr, string, 0)


# Approach 2 --
def countSetBits(bitSet):

    count = 0

    while(bitSet):

        count += bitSet & 1
        bitSet  >>= 1

    return count

def stringConcatenation(arr):
    bitArr = [0]
    res = 0

    for string in arr:

        bitSet = 0

        for ch in string:
            bitSet  |= (1 << (ord(ch) - ord('a')))

        n = countSetBits(bitSet)

        if(n < len(string)):
            continue

        for currBitSet in bitArr:
            if (currBitSet & bitSet):
                continue

            bitArr.append(currBitSet | bitSet)
            res = max(res, countSetBits(currBitSet) + n)

    return res

