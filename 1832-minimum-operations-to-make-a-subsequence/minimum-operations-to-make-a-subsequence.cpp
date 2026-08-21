class Solution {
public:
    int minOperations(vector<int>& target, vector<int>& arr) {
        vector<int> v;
        unordered_map<int,int> mp;
        for(int i=0;i<target.size() ;i++){
            mp[target[i]]=i;
        }
        vector<int> ar;
        for(auto x:arr){
            if(mp.find(x) == mp.end()) continue;
            ar.push_back(mp[x]);
        }
        vector<int> dp;
        if(ar.empty()) return target.size();

        dp.push_back(ar[0]);
        for(int i=1;i<ar.size();i++){
            auto it=lower_bound(dp.begin() , dp.end()  , ar[i]);
            if(it==dp.end()) dp.push_back(ar[i]);
           else *it=ar[i];
        }
        return target.size()-dp.size();
    }
};