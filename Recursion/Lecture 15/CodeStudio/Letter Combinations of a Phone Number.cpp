#include <bits/stdc++.h>
using namespace std;

void help(int i, string &s, string &temp, vector<string> &ans, unordered_map<char, string> &m)
{
    // base condition
    // i : current Index
    // if we have reached till the end of the string s then include temp into ans[][]
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }

    // this gives the entire string that is present in the map m corresponding to the ith element in the string s
    // eg: s = 2 3, i = 1
    //     str = m[s[i]] = m[s[1]] = m[3] = def
    string str = m[s[i]];

    // loop for traversing every element in str
    for (int j = 0; j < str.size(); j++)
    {
        // do the small task
        temp.push_back(str[j]);

        // ask recursion to do the remaining task
        help(i + 1, s, temp, ans, m);

        // backtrack & undo the changes that were made
        temp.pop_back();
    }
}

vector<string> combinations(string s)
{
    // for solving this problem we need to know what all characters are represented by each of the numbers
    // therefore we are storing all the corresponding characters from digit 2 to 9 in the unordered_map<char, string> m
    unordered_map<char, string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";

    vector<string> ans;
    string temp;
    help(0, s, temp, ans, m);
    return ans;
}

/*
    time complexity: O(3^N)
    space complexity: O(N)
*/