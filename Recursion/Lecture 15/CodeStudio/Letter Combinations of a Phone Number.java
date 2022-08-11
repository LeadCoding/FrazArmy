import java.util.ArrayList;
import java.util.*;
public class Solution 
{
    static void help(int i, String s, String temp, ArrayList<String> ans, HashMap<Character, String> m)
    {
        // If i has reached till the end of given string, we have reached a Valid Combination
        // We should include it into ans and return back

        if (i == s.length())
        {
            ans.add(temp);
            return;
        }

        // Since, we have mapped all the digits with their corresponding Letters
        // m.get( s.charAt(i) ) will give us the actual string corresponding to that digit using HashMap m
        
        char chr = s.charAt(i);
        String str = m.get(chr);

        // loop for traversing every element in str

        for (int j = 0; j < str.length(); j++)
        {
            
            char c = str.charAt(j);

            // Ask recursion to do rest of the task

            help(i + 1, s, temp + c, ans, m);

        }
    }
    public static ArrayList<String> combinations(String s)
    {
        // To solve this question, we need to map all the letters of a particular digit with it's corresponding digit. This is done with the help of HashMap <Character,String> m.

        HashMap<Character,String> m = new HashMap<>();
        m.put('2',"abc");
        m.put('3',"def");
        m.put('4',"ghi");
        m.put('5',"jkl");
        m.put('6',"mno");
        m.put('7',"pqrs");
        m.put('8',"tuv");
        m.put('9',"wxyz");

        ArrayList<String> ans = new ArrayList<>();

        if(s.length() == 0)
            return ans;
        
        String temp = "";

        help(0 , s , temp , ans , m) ;

        return ans;
    }
}

/*
Time Complexity: O(3^N)
Space Complexity: O(N)
*/
