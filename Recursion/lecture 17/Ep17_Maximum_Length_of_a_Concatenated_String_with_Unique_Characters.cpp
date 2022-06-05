// Approach 1--
int dfs(vector<string> &strings, string currString, int position)
{
    unordered_set<char> st ;

    for(int i = 0; i < currString.length(); i++)
    {  
        char ch = currString[i];
        st.insert(ch);
    }

    if (st.size() != currString.length())
    {
        return 0;
    }

    int res = currString.length();

    for(int currPos = position; currPos < strings.size(); currPos++)
    {
        string str = strings[currPos];
        res = max(res, dfs(strings, str + currString, currPos + 1));
    }

    return res;
}

int stringConcatenation(vector<string> &arr)
{
    string str = "";
    return dfs(arr, str, 0);
}


// Approach 2 --
int countSetBits(int bitSet)
{
    int count = 0;
    while(bitSet) {
        count += bitSet & 1;
        bitSet  >>= 1;
    }

    return count;
}

int stringConcatenation(vector<string> &arr)
{
    vector<int> bitArr = {0};
    int res = 0;

    for(int i = 0; i < arr.size(); i++)
    {   
        string str = arr[i];

        int bitSet = 0;

        for(int j = 0; j < str.length(); j++)
        {   
            char ch = str[j];
            bitSet  |= (1 << (ch - 'a'));
        }

        int n = countSetBits(bitSet);

        if(n < str.length())
        {
            continue;
        }

        for(int j = 0; j < bitArr.size(); j++)
        {   
            int currBitSet = bitArr[j];
            if (currBitSet & bitSet) {
                continue;
            }

            bitArr.push_back(currBitSet | bitSet);
            res = max(res, countSetBits(currBitSet) + n);
        }
    }

    return res;
}