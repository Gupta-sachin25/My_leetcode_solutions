class Solution {
public:

bool solve(int ind , vector<int> &dp){
    if(ind<=0) return dp[ind]= false;
    if(dp[ind]!=-1) return dp[ind];
    bool ans=true;
    for(int j=1 ; j*j<=ind ; j++){
        ans = ans & solve(ind - j*j , dp);
    }
    if(ans==false) return dp[ind]=true;
    return dp[ind]=false;
}
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1 , -1);
        solve( n , dp);
        return dp[n];
    }
};