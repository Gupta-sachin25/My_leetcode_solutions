class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int mini=nums[k];
        int ans=nums[k];
        int i=k , j=k;
        int n=nums.size();
        if(nums.size() ==1) return nums[k];
        while(i>0 || j<n-1){
            if(i==0){
                j++;
                mini=min(nums[j] , mini);
                ans=max(ans , mini*(j-i+1));
                continue;
            }
            if(j==n-1){
                i--;
                mini=min(nums[i] , mini);
                ans=max(ans , mini*(j-i+1));
                continue;
            }
            if(nums[i-1] > nums[j+1]){
                i--;
                mini=min(nums[i] , mini);
                ans=max(ans , mini * (j-i+1));
                continue;
            }
            j++;
            mini=min(nums[j] , mini);
            ans=max(ans , mini*(j-i+1));
            continue;
        }
        return ans;
    }
};