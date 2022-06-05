// Approach 1 --
import java.util.HashSet;
public class Solution {
    private static int dfs(String[] strings, String currString, int position) {
        HashSet<Character> st = new HashSet<>();
        for (int i = 0; i < currString.length(); i++) {
            char ch = currString.charAt(i);
            st.add(ch);
        }

        if (st.size() != currString.length()) {
            return 0;
        }

        int res = currString.length();

        for (int currPos = position; currPos < strings.length; currPos++) {
            String str = strings[currPos];
            res = Math.max(res, dfs(strings, str + currString, currPos + 1));
        }

        return res;
    }

    public static int stringConcatenation(String[] arr) {
        String str = "";
        return dfs(arr, str, 0);
    }

}

// // Approach 2 --
import java.util.ArrayList;
public class Solution {

	private static int countSetBits(int bitSet) {
		int count = 0;

		while (bitSet > 0) {
			count += bitSet & 1;
			bitSet >>= 1;
		}

		return count;
	}

	public static int stringConcatenation(String[] arr) {
		ArrayList<Integer> bitArr = new ArrayList<>();
		bitArr.add(0);
		int res = 0;

		for (int i = 0; i < arr.length; i++) {
			String str = arr[i];

			int bitSet = 0;

			for (int j = 0; j < str.length(); j++) {
				char ch = str.charAt(j);
				bitSet |= (1 << (ch - 'a'));
			}

			int n = countSetBits(bitSet);
			if (n < str.length()) {
				continue;
			}

			for (int j = 0; j < bitArr.size(); j++) {
				int currBitSet = bitArr.get(j);
				if ((currBitSet & bitSet) > 0) {
					continue;
				}

				bitArr.add(currBitSet | bitSet);
				res = Math.max(res, countSetBits(currBitSet) + n);
			}
		}

		return res;
	}
}