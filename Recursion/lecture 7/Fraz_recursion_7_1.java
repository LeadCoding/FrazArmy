ArrayList<ArrayList<Integer>> ans;
ArrayList<Integer> temp;

    ArrayList<ArrayList<Integer>> helper(ArrayList<Integer> v, int i) {
        ArrayList<ArrayList<Integer>> partialAns = helper(v, i + 1);

        for (ArrayList<Integer> x : partialAns) {
            ans.add(x);
        }
        for (ArrayList<Integer> x : partialAns) {

            temp.add(v.get(i));
            for (int y : x) {
                temp.add(y);
            }
            ans.add(temp);
        }
        return ans;
    }

    ArrayList<ArrayList<Integer>> pwset(ArrayList<Integer> v) {
        return helper(v, 0);
    }