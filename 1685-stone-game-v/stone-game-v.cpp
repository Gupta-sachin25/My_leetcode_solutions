class Solution {
public:

int solve(vector<vector<int>> &dp ,vector<int> &prf ,  int i , int j  )
{
    if(i==j) return dp[i][i]= 0;
    if(dp[i][j] != -1) return dp[i][j];

    int ans=0;

    for(int ind = i; ind < j; ind++) { 
            
            int leftsum = prf[ind + 1] - prf[i]; 
            int rightsum = prf[j + 1] - prf[ind + 1]; 
 
            if(leftsum < rightsum) { 
                ans = max(ans, leftsum + solve(dp, prf, i, ind)); 
            } 
            else if(leftsum > rightsum) { 
                ans = max(ans, rightsum + solve(dp, prf, ind + 1, j)); 
            } 
            else { 
                ans = max(ans, leftsum + solve(dp, prf, i, ind)); 
                ans = max(ans, rightsum + solve(dp, prf, ind + 1, j)); 
            } 
        } 
 
        return dp[i][j] = ans;

}
    int stoneGameV(vector<int>& sv) {
        int n=sv.size();
        vector<int> prf(n+1 , 0);
        vector<vector<int>> dp(n+1 , vector<int>(n+1 , -1));
for(int i = 0; i < n; i++) {
            prf[i + 1] = prf[i] + sv[i];
        } 
        return solve(dp, prf, 0, n - 1);
    }
};