import java.util.*;

public class Solution {
    private static ArrayList<ArrayList<Integer>> subsets;
    private static ArrayList<Integer> cur;
    private static int count;

    private static void pwr(int st, int[] arr) {
        if (count >= 0) {
            ArrayList<Integer> temp = new ArrayList<Integer>();
            subsets.add(temp);
            for (int i = 0; i < cur.size(); i++) {
                temp.add(cur.get(i));
            }
            subsets.set(count, temp);
            count++;
        }

        for (int i = st; i < arr.length; i++) {

            if ((i == st) || (arr[i] != arr[i - 1])) {

                cur.add(arr[i]);
                pwr(i + 1, arr);
                cur.remove(cur.size() - 1);
            }
        }
    }

    public static ArrayList<ArrayList<Integer>> uniqueSubsets(int n, int arr[]) {
        subsets = new ArrayList<ArrayList<Integer>>();
        cur = new ArrayList<Integer>();
        Arrays.sort(arr);
        count = 0;
        pwr(0, arr);

        return subsets;
    }
}
