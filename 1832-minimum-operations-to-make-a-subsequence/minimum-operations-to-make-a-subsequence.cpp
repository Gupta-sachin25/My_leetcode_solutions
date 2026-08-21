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

         for(int x : ar) {
            auto it = lower_bound(dp.begin(), dp.end(), x);

            if(it == dp.end())
                dp.push_back(x);
            else
                *it = x;
        }
        return target.size()-dp.size();
    }
};