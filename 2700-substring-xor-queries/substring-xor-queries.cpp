class Solution {
public:
/*
a^b=c so a will be c^b
to find a , we hav eto go for atmax 32 +i 
*/
    vector<vector<int>> substringXorQueries(string s, vector<vector<int>>& q) {
        unordered_map<int , vector<int> > mp;int n=s.size();
        for(int i=0;i<n;i++){
             if (s[i] == '0') {
                if (!mp.count(0)) {
                    mp[0] = {i, i};
                }
                continue;
            }
            int ct=0;
            int num=0;
            long long temp=1;
            for(int j=i;j < n && j < i + 30;j++){
               ct++;
                 num = num * 2 + (s[j] - '0');

                if (mp.find(num) == mp.end()) {
                    mp[num] = {i, j};
                }
            }    
        }


        
         vector<vector<int>> ans;

         for(auto x:q){
            int fs=x[0] , sc=x[1];
            if(mp.find(fs^sc)!=mp.end()){
                ans.push_back(mp[fs^sc]);
            }
            else ans.push_back({-1,-1});
         }

         return ans;
    }
};