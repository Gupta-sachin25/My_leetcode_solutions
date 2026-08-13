class Solution {
public:

int solve(vector<vector<int>> &dp , vector<int> &nums , int i , int j , int sum ){
    if(j < -sum || j > sum) return 0;
    if(i>=nums.size() && j!=0) return 0;
    if(i>=nums.size() && j==0) return 1;
    if(dp[i][j+sum]!=INT_MIN) return dp[i][j+sum];
    int pos=0 , neg=0;

    pos = solve(dp , nums , i +1, j-nums[i] , sum);
    neg = solve(dp , nums , i +1, j+nums[i] , sum);

    return dp[i][j+sum]=pos+neg;

}
    int findTargetSumWays(vector<int>& nums, int target) {
      int tot=0;
              int sum = 0;
        for(int x : nums)
            sum += x;

        if(abs(target) > sum)
            return 0;

            vector<vector<int>> dp(nums.size()+1 , vector<int> (2*sum+1 , INT_MIN)); 
        return solve(dp , nums , 0 , target , sum);
    }
};