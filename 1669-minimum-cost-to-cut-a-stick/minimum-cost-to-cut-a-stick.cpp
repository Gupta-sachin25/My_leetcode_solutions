class Solution {
public:

 vector<vector<int>> dp;
 vector<int> v;

    int minCost(int n, vector<int>& c) {
       v=c;
       sort(v.begin(),v.end());
       v.insert(v.begin(),0);
       v.push_back(n);

       int m=v.size();
       dp.resize(m,vector<int>(m,0));

       for(int i=m-2;i>=1;i--){
           for(int j=i;j<=m-2;j++){
               int cost=INT_MAX;

               for(int k=i;k<=j;k++){
                   int temp=v[j+1]-v[i-1]+dp[i][k-1]+dp[k+1][j];
                   cost=min(cost,temp);
               }

               dp[i][j]=cost;
           }
       }

       return dp[1][m-2];
    }
};