class Solution {
public:

    int solve(int si , int li , vector<vector<int>> &dp , vector<int> &a){
        if(si==li) return dp[si][li] = a[si] ;
        if(dp[si][li] != -1) return dp[si][li] ;
        // if i choose left
        int lef = a[si] -solve(si+1 , li , dp , a);
        int rig = a[li]-solve(si , li-1 , dp , a);
        return dp[si][li] = max(lef , rig);

    }

bool predictTheWinner(vector<int>& nums) {
        int n= nums.size() ;
        vector<vector<int>> dp(n+1 , vector<int> (n+1 , -1));
        solve(0 , n-1 , dp , nums);
    return dp[0][n-1] >=0;
    }
};