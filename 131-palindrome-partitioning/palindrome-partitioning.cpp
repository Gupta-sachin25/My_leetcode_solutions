class Solution {
public:

bool ispal(string &s , int si , int li){
    while(si<=li){
        if(s[si]!=s[li]) return false;
        si++;
        li--;
    }
    return true;
}
void backtrack(string &s , int ind , vector<string> &p , vector<vector<string>> &res){
    if(ind==s.size()){
        res.push_back(p);
        return;
    }
    for(int i=ind;i<s.size();i++){
if(ispal(s , ind , i )){
p.push_back(s.substr(ind , i-ind+1));
backtrack(s , i+1 , p , res);
p.pop_back();

}


    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> path;
        backtrack(s , 0 , path , res);
        return res;
    }
};