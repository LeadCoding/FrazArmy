import java.util.*;

public class Solution {
    private static void permute(ArrayList<String> ans, String str, int curr, int n)
    {
        // when we have traversed the entire str, then we should put str into ans[]
        if (curr == n)
            ans.add(str);
        else
        {
            // Iterating from currentposition till size of str and trying to generate all possible Permutations 
            for (int i = curr; i < n; i++)
            {
                // call swap function for swapping the ith element with the current element
                str = swap(str,curr,i);

                // ask recursion to do the remaining task
                permute(ans, str, curr+1, n);

                // backtrack & undo the changes
                str = swap(str,curr,i);
            }
        }
    }

    // function that will swap the ith element with the current element
    public static String swap(String s, int i, int j)
    {
        char temp;
        char[] strArray = s.toCharArray();
        temp = strArray[i] ;
        strArray[i] = strArray[j];
        strArray[j] = temp;
        return String.valueOf(strArray);
    }
    
    public static ArrayList<String> generatePermutations(String str) {
        // Write your code here
        ArrayList<String> ans = new ArrayList<>();
        int n = str.length();
        permute(ans, str, 0, n);

        // Specific to this problem because we want the strings sorted in lexicographical order
        Collections.sort(ans);
        return ans;
    }
}

/* 
    time complexity : O(n * n!)
    space complexity : O(n)
*/