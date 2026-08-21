class Solution {
public:

static bool cmp(vector<int> &a , vector<int> &b){
    if(a[0]<b[0]) return true;
if(a[0]>b[0]) return false;
if(a[1]>b[1]) return true;
return false;
}


    int maxEnvelopes(vector<vector<int>>& e) {
        int n=e.size();
        sort(e.begin() , e.end() , cmp);
        
       vector<int> dp;
       for(int i=0;i<n;i++){
    int w=e[i][0] , h=e[i][1];
    if(dp.empty()){
        dp.push_back(h);
        continue;
    }
    auto it =lower_bound(dp.begin() , dp.end() , h);
    if(it==dp.end()) {dp.push_back(h);continue;}
    dp[it-dp.begin()]=h;

       }

    
return dp.size();
    }
};