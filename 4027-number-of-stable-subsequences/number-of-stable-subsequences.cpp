class Solution {
public:
int mod=1e9+7;
vector<int> v;

int solve( vector<vector<vector<int>>> &dp , int i , int l , int ll){
    if(i>=v.size()) return 0;
    if(dp[i][l][ll] !=-1) return dp[i][l][ll];
    int nottake=solve(dp , i+1,l , ll);
    // l =1 ie od and l=0 ie even
    int take=0;
    if(l==0){
        take= 1+ solve(dp , i+1 ,v[i]%2+1 , ll );
    }
    else if(ll==0){
        take= 1+ solve(dp , i+1 ,v[i]%2+1 , l );
    }
    else{
        if(l!=ll || v[i]%2!=l-1){
            take=1+solve(dp , i+1 , v[i]%2+1 , l);
        }
    }
    return dp[i][l][ll]=(take+nottake)%mod;
    
     return 0;}

    int countStableSubsequences(vector<int>& nums) {
        v=nums;
        vector<vector<vector<int>>> dp(nums.size()+1 , vector<vector<int>> 
        (3 , vector<int> (3 , -1)));
return solve(dp,0,0,0);

     return 0;   
    }
};