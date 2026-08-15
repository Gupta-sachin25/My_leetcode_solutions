class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        // given nums[i] is 0 or >0
        long long  xr=0, sum=0;
        for(auto x: nums){
            xr^=x;
            sum+=x;
        }
        if(xr) return nums.size();
        if(sum){
            return nums.size()-1;
        }
        return 0;
    }
};