ArrayList<ArrayList<Integer>> ans;
ArrayList<Integer> subSet;

void helper(ArrayList<Integer> v, int i, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans) {
        if (i == v.size()) {
            ans.add(new ArrayList(subSet));
            return;
        }
        // include the ith element
        subSet.add(v.get(i));
        helper(v, i + 1, subSet, ans);
        // not including the ith element
        subSet.remove(subSet.size()-1);
        helper(v, i + 1, subSet, ans);
}

ArrayList<ArrayList<Integer>> pwset(ArrayList<Integer> v) {
        helper(v, 0, subSet, ans);
        return ans;
}
