boolean isPalindromeHelper(int l,int r,String s)
{
    if(l>=r) return true;
    if(s.charAt(l)!=s.charAt(r)) return false;
    return isPalindromeHelper(l+1,r-1,s);

}
boolean isPalindrome(String s)
{
    return isPalindromeHelper(0,s.size()-1,s);
}