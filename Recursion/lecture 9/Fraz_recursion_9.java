public static HashSet<String> h = new HashSet<String>();
    ArrayList<String> ans = new ArrayList<>();

    public void permute(char s[], int i, int n) {

        // If the permutation is complete
        if (i == n) {

            // If set doesn't contain
            // the permutation already
            if (!(h.contains(String.copyValueOf(s)))) {

                h.add(String.copyValueOf(s));

                ans.add(String.copyValueOf(s));
            }
        }

        else {

            // One by one swap the jth
            // character with the ith
            for (int j = i; j <= n; j++) {

                // Swapping a[i] and a[j];
                char temp = s[i];
                s[i] = s[j];
                s[j] = temp;

                // Revert the swapping or backtracking
                permute(s, i + 1, n);

                temp = s[i];
                s[i] = s[j];
                s[j] = temp;
            }
        }
    }

    ArrayList<String> generatePermutations(String str) {

        char[] ch = str.toCharArray();
        permute(ch, 0, ch.length - 1);
        Collections.sort(ans);
        return ans;
    }