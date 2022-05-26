void helper(ArrayList<Integer> v, int i, ArrayList<Integer> subSet, ArrayList<ArrayList<Integer>> ans) {
    if (i == v.size()) {
        ans.add(subSet);
        return;
    }
    // include the ith element
    subSet.add(v.get(i));
    helper(v, i + 1, subSet, ans);
    // not including the ith element
    subSet.remove(subSet.get(subSet.size() - 1));
    while (i + 1 < v.size() && v.get(i) == v.get(i + 1))
        i++;
    helper(v, i + 1, subSet, ans);
}

ArrayList<ArrayList<Integer>> pwset(ArrayList<Integer> v) {
    ArrayList<ArrayList<Integer>> ans = new ArrayList<>();
    ArrayList<Integer> subSet = new ArrayList<>();
    helper(v, 0, subSet, ans);
    // Collections.sort(ans);
    return ans;
}