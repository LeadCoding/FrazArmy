#include <bits/stdc++.h>
using namespace std;

// this function will compare currString with the history of all the previously selected characters present inside vector<int> selected
bool compare(vector<int> &selected, string &currString)
{
    // before we compare currString with other string first we need to make sure that all the characters in the currString are distinct therefore we are creating vector<int> selfCheck(26, 0) for selfChecking the currString
    // this is a vector of size 26 with all value initialized to 0 for keeping track of all the characters in the currString
    vector<int> selfCheck(26, 0); 

    // loop for checking whether each & every character in the currString are distinct or not
    for (int i = 0; i < currString.size(); i++)
    {
        // this means that the characters in the currString are not distinct & there are duplicate characters present in it
        // therefore we cannot use this currString hence return false
        if (selfCheck[currString[i] - 'a'] == 1)
            return false;

        // assigning 1 to the index of selfCheck[currString[i] - 'a']  for character currString[i] as it is present in the currString
        selfCheck[currString[i] - 'a'] = 1;
    }

    // loop for comparing currString with already selected characters that are present in the vector<int> selected
    for (int i = 0; i < currString.size(); i++)
    {
        // if currString[i] is already present in selected then return false
        if (selected[currString[i] - 'a'] == 1)
            return false;
    }

    // else if it is not present then return true
    return true;
}


int help(int i, vector<string> &arr, vector<int> &selected, int len)
{
    // base condition
    if (i == arr.size())
    {
        return len;
    }

    string currString = arr[i];

    // if there is an overlap of characters that is the characters are not unique then don't select the currString
    if (compare(selected, currString) == false)
    {
        // skip the currString
        return help(i + 1, arr, selected, len);
    }

    // else there are no overlap of characters as well as all the characters are unique
    // hence we have two options one to pick the currString or to skip it & then compare both to get the best answer out of it
    else
    {
        // pick the currString
        for (int j = 0; j < currString.size(); j++)
        {
            // mark the indices as 1 so that in future we know that what all characters we have selected
            selected[currString[j] - 'a'] = 1;
        }

        // increase the length 
        len += currString.size();

        // ask recursion to do rest of the task
        int op1 = help(i + 1, arr, selected, len);

        // skip the currString
        // first of all the indices which we have been marked 1 need to get changed to 0 because we are not picking currString this time
        for (int j = 0; j < currString.size(); j++)
        {
            selected[currString[j] - 'a'] = 0;
        }

        // decrease the length 
        len -= currString.size();

        // ask recursion to do rest of the task
        int op2 = help(i + 1, arr, selected, len);

        // finally we will return the maximum of length in between op1 & op2
        return max(op1, op2);
    }
}


int stringConcatenation(vector<string> &arr)
{
    // making a new vector with size of 26 where all values are initialized with 0
    // this vector will keep track of the history of all the characters present inside each string of vector<string> arr
    vector<int> selected(26, 0); 
    return help(0, arr, selected, 0);
}

/*
    time complexity: O(k * 2^N)
    space complexity: O(N)
*/