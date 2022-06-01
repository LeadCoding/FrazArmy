import java.util.ArrayList;

class login {
    void help(int i, int k, int sumTillNow, int n, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans) {

        if (sumTillNow > n)
            return;
        if (k == 0) {
            if (sumTillNow == n) {
                ans.add(subSet);
            }
            return;
        }
        // if( k < 0) return;
        // if(sumTillNow == n) {
        // if( k == 0) {
        // ans.push_back(subSet);
        // }
        // return;
        // }

        if (i == 10)
            return;
        // pick
        sumTillNow += i;
        subSet.add(i);
        help(i + 1, k - 1, sumTillNow, n, subSet, ans);
        sumTillNow -= i;
        subSet.remove(subSet.size() - 1);

        // ignore
        help(i + 1, k, sumTillNow, n, subSet, ans);

    }

    ArrayList<ArrayList<Integer>> combinationSum3(int k, int n) {
        ArrayList<Integer> subSet = new ArrayList<>();
        ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
        help(1, k, 0, n, subSet, ans);
        return ans;
    }
}