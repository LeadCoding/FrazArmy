void combinationsHelper(string digits, string digToStr[], int j, string temp, vector<string>&ans){
    if(j == digits.length()){
        ans.push_back(temp);
        return;
    }
    
    int val = digits[j]-'0';
    for(int i=0;i<digToStr[val].size();i++){
        temp.push_back(digToStr[val][i]);
        combinationsHelper(digits,digToStr,j+1,temp,ans);
        temp.pop_back();   
    }
}
    
vector<string> combinations(string s){
	string digToStr[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    
    int n =  s.length();
    string temp;
    vector<string>ans;
    
    if(n == 0) {
    	return ans;
    }
    combinationsHelper(s,digToStr,0,temp,ans);
    return ans;
}