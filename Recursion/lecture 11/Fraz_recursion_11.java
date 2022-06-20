import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;

public class Solution {
	private static ArrayList<ArrayList<Integer>> ans;
	private static ArrayList<Integer> cur;
	private static int count;

	private static void rec(int idx, int n, int k) {
		if (k > (n - idx + 1)) {
			return;
		}

		if (k == 0) {
			if (count >= 0) {
				ArrayList<Integer> temp = new ArrayList<Integer>();
				ans.add(temp);
			}
			for (int c = 0; c < cur.size(); c++) {
				ans.get(count).add(cur.get(c));
			}
			count++;
			return;
		}
		rec(idx + 1, n, k);

		cur.add(idx);
		rec(idx + 1, n, k - 1);
		cur.remove(cur.size() - 1);
	}

	public static ArrayList<ArrayList<Integer>> combinations(int n, int k) {
		ans = new ArrayList<ArrayList<Integer>>();
		cur = new ArrayList<Integer>();
		count = 0;

		rec(1, n, k);

		Collections.sort(ans, new Comparator<ArrayList<Integer>>() {
			public int compare(ArrayList<Integer> a, ArrayList<Integer> b) {
				int x = a.size();
				for (int i = 0; i < x; i++) {
					if ((int) a.get(i) == (int) b.get(i))
						continue;
					else if ((int) a.get(i) > (int) b.get(i))
						return 1;
					else
						return -1;
				}
				return 1;
			}
		});

		return ans;
	}
}