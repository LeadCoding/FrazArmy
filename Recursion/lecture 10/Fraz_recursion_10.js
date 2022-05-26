const helper = (v, i, subSet, ans) => {
    // one of many ways of referencing object in JS
    let subSetRef = JSON.parse(JSON.stringify(subSet));
    
    if (i === v.length)
    {
        ans.push(subSetRef);
        return;
    }
    // include the ith element
    
    subSetRef.push(v[i]);
    helper(v, i + 1, subSetRef, ans);
    // not including the ith element
    subSetRef.pop();
    while (i + 1 < v.length && v[i] === v[i + 1])
    {
        i++;
    }
    helper(v, i + 1, subSetRef, ans);
}
var pwset = (v) => {
    let ans = [];
    let subSet = [];
    helper(v, 0, subSet, ans);
    ans.sort();
    return ans;
};