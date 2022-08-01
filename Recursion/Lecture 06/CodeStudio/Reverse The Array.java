import java.util.ArrayList;
import java.util.Collections;
public class Solution 
{
    static int helper(int l, int r,ArrayList<Integer> arr){
        // base condition
        if(l>=r) return 1;

        // do the small task
        Collections.swap(arr, l, r);

        // ask recursion to do the remaining task
        return helper(l+1,r-1,arr);
    }
    public static void reverseArray(ArrayList<Integer> arr, int m)
    {
        // Write your code here.
        helper(m+1,arr.size()-1,arr);
    }
}


/*
    time complexity : O(n)
    space complexity : O(n)
*/