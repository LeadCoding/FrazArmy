vector<vector<int>> helper(vector<int> &v,int i)
{
    //base condition
    if(i>=v.size()) return {{}};
    vector<vector<int>> partialAns = helper(v,i+1);
    vector<vector<int>> ans;
    for(vector<int> x:partialAns)
    {
        ans.push_back(x);
    }
    for(vector<int> x:partialAns){
        vector<int> temp;
        temp.push_back(v[i]);
        for(int y:x)
        {
            temp.push_back(y);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int>> pwset(vector<int>v)
{
    return helper(v,0);
}
