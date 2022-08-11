/* This problem asks us to find the Max Length of Concatenated strings present inside arr[]
All the concatenated strings should have unique characters
*/

public class Solution 
{
    static boolean compare(int[] selected, String currString)
    {
        // Before checking with selected[], we need to check if currString has repeating characters or Not

        // This is done using selfCheck array which checks if currString has repeating characters or Not

        int selfCheck[] = new int[26]; 

        for (int i = 0; i < currString.length(); i++)
        {
            // As all the characters are present in LowerCase, we can use character at currString - 'a' to map every character to a corresponding index (as discussed thoroughly in the lecture)

            // If currCharacter is already taken, it means currString has repeating characters
            
            int currCharacter = currString.charAt(i) - 'a';

            if (selfCheck[currCharacter] == 1)
                return false ;

            // Else we mark all the characters inside SelfCheck as 1

            selfCheck[currCharacter] = 1 ;
        }

        // The second Loop ensures whether the characters of currString has already been selected or not

        for (int i = 0; i < currString.length(); i++)
        {
            // If currCharacter is already taken, it means we cannot take currString, thus we return false
            
            int currCharacter = currString.charAt(i) - 'a';

            if (selected[currCharacter] == 1)
                return false ;
        }


        // At the end, if currString doesn't contain repeating characters AND it's characters have already not been taken yet, we return true indicating currString can be chosen now

        return true ;
    }


    static int help(int i, String[] arr, int[] selected, int len)
    {
        // If we reach till the end of arr[], we need to return the max Length we have taken till now

        if (i == arr.length )
        {
            return len ;
        }

        String currString = arr[i] ;

        // If currString contains Duplicate Characters or it's characters have already been taken, we have no option but to skip curr String and move to next Index

        if (compare(selected, currString) == false)
        {
            // skip the currString
            return help(i + 1, arr, selected, len) ;
        }

        // Else we have two options, One to include CurrString OR another option is to Skip CurrString

        else
        {
            // If we pick the currString, all it's characters must be marked as taken in selected [] array

            for (int j = 0; j < currString.length(); j++)
            {
                int currCharacter = currString.charAt(j) - 'a';
                selected[currCharacter] = 1 ;
            }

            // Increase the length by currString.length() 

            len += currString.length() ;

            // Ask Recursion to do rest of task

            int op1 = help(i + 1, arr, selected, len) ; 

            // Backtrack and unmark all the characters of currString as NOT TAKEN in selected[] array

            for (int j = 0; j < currString.length(); j++)
            {
                int currCharacter = currString.charAt(j) - 'a';
                selected[currCharacter] = 0 ;
            }

            // As we are not including currString, we should decrease len by currString.length()

            len -= currString.length() ;

            // Ask recursion to do rest of the task

            int op2 = help(i + 1, arr, selected, len) ;

            // Lastly, we will return the max of (op1 , op2) whichever brings the Longest Length

            return Math.max(op1, op2) ;
        }
    }
	public static int stringConcatenation(String[] arr) 
    {
	    // selected [] vector will keep track of all the characters which have been taken yet
        
        int[] selected = new int[26] ; 

        return help(0, arr, selected, 0);
	}
}

/*
    Time Complexity:  O(K * 2^N)
    Space Complexity: O(N)
*/
