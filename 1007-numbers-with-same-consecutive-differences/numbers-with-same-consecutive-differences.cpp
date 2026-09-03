class Solution {
public:

vector<int> ans;

    void solve(string s , int n , int k){
        if(s.size()==n){
            ans.push_back(stoi(s));
            return;
        }
        int num=s[s.size()-1]-'0';
        if(num+k <=9 ) {
                s.push_back(num+k+'0');
                solve(s , n ,k);
                s.pop_back();
        }
        if(num-k >=0){
             s.push_back(num-k+'0');
                solve(s , n , k);
                s.pop_back();
        }
        return;
    }

    vector<int> numsSameConsecDiff(int n, int k) {
        ans.resize(0);
        for(int i=1;i<=9;i++){
            solve(to_string(i) , n,k);
        }
        ranges:: sort(ans);
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};