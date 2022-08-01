/* This question requries us to print all Valid Combinations of the given string digits which comprises of digits from 2 to 9.
The only thing we require extra in this question is to map all the letter combinations of the phone number to its corresponding digits.
The rest part of the question remains exactly same
*/

class Solution {
private:
    
void help(int i, string &s, string &temp, vector<string> &ans, unordered_map<char, string> &m)
{
    // If i has reached till the end of given string, we have reached a Valid Combination
    // We should include it into ans[][] and return back
    
    if (i == s.size())
    {
        ans.push_back(temp);
        return;
    }

    // Since, we have mapped all the digits with their corresponding Letters
    // m[s[i]] will give us the actual string corresponding to that digit using unordered_map m
    
    string str = m[s[i]];

    // loop for traversing every element in str
    
    for (int j = 0; j < str.size(); j++)
    {
        // Push the i-th character of str into our temp string
        
        temp.push_back(str[j]);

        // Ask recursion to do rest of the task
        
        help(i + 1, s, temp, ans, m);

        // Backtrack and undo the change we have already done
        
        temp.pop_back();
    }
}
    
public:
    vector<string> letterCombinations(string digits) {
      
    // As per the problem, for an empty string, we need to return an empty vector
        
    if(digits.size() == 0)
    return {} ;
        
    // To solve this question, we need to map all the letters of a particular digit with it's corresponding digit. This is done with the help of unordered_map<char , string> m.
        
    unordered_map<char, string> m;
    m['2'] = "abc";
    m['3'] = "def";
    m['4'] = "ghi";
    m['5'] = "jkl";
    m['6'] = "mno";
    m['7'] = "pqrs";
    m['8'] = "tuv";
    m['9'] = "wxyz";

    vector<string> ans ;
        
    string temp ;
        
    help(0 , digits , temp , ans , m) ;
         
    return ans;
        
}
};

/*
Time Complexity: O(3^N)
Space Complexity: O(N)
*/
