bool isPalindromeNumber(int l, int r, string &s)
{
    // base condition
    // l : left pointer, r : right pointer
    if (l >= r)
        return true;

    // base condition
    // when character at s[left] is not equal to character at s[right] that means it is not a palindrome thus return false
    if (s[l] != s[r])
        return false;

    // recursion call
    return isPalindromeNumber(l + 1, r - 1, s);
}

bool isPalindrome(string &s)
{
    // Write your code here.
    // here we are going to use two pointer approach
    // left pointer starting from first index 0
    // right pointer starting from last index s.size() - 1
    return isPalindromeNumber(0, s.size() - 1, s);
}

/*
    time complexity : O(n)
    space complexity : O(n)
*/