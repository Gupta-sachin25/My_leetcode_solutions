class Solution {
public:
vector<bool> isArraySpecial(vector<int>& a, vector<vector<int>>& q) {
        int n=a.size();
        bool flag=true;
        vector<int> ind(1,0);
        for(int i=1;i<a.size();i++){
            if((a[i] % 2) != (a[i-1] %2)) continue;
            // ind.push_back(1);
            ind.push_back(i);
        }
        
        vector<bool> ans;
        for(auto it: q){
            int si=it[0] , ei=it[1];
            auto temp=upper_bound(ind.begin() , ind.end(),si);
            auto temp2=upper_bound(ind.begin() , ind.end(),ei);
            if(temp==temp2) ans.push_back(true);
            else ans.push_back(false);
        }
return ans;
    }
};