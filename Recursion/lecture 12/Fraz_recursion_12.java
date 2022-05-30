import java.util.*;

public class Solution {
    public static ArrayList<ArrayList<Integer>> result;

    private static void solve(ArrayList<Integer> currList, int currIndex, int currSum, int b, ArrayList<Integer> arr) {
        if (currSum == b) 
        {
            result.add(new ArrayList<Integer>(currList));
            return;
        }
        if (currIndex == arr.size()) 
        {
            return;
        }

        solve(currList, currIndex + 1, currSum, b, arr);

        int count = 0;

        while (currSum <= b) 
        {
            count++;

            currSum += arr.get(currIndex);

            currList.add(arr.get(currIndex));

            solve(currList, currIndex + 1, currSum, b, arr);
        }
        while (count > 0) 
        {
            int index = currList.size() - 1;
            currList.remove(index);
            count--;
        }
    }

    public static ArrayList<ArrayList<Integer>> combSum(ArrayList<Integer> arr, int b) 
    {

        Collections.sort(arr);
        result = new ArrayList<ArrayList<Integer>>();
        ArrayList<Integer> currList = new ArrayList<Integer>();
        solve(currList, 0, 0, b, arr);
        return result;
    }
}