#include<bits/stdc++.h>
void perm(int pos,string &str,vector<string> &ans)
{
    if(pos>=str.size()){
        ans.push_back(str);
    }
    for(int i=pos;i<str.size();i++)
    {
        swap(str[i],str[pos]);
        perm(pos+1,str,ans);
        swap(str[i],str[pos]);//backtracking
    }
}

vector<string> generatePermutations(string &str)
{
    vector<string> ans;
    perm(0,str,ans);
    sort(ans.begin(),ans.end());
    return ans;
}