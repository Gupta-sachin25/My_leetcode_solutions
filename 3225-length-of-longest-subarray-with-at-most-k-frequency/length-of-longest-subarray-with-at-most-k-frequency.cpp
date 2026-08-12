class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int len=0 , i=0 , j=0;int n=nums.size();
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]>k){
                while(nums[i]!=nums[j]) mp[nums[i++]]--;
                i++;
                  mp[nums[j]]--;
            }
            len=max(len , j-i+1);
          
            j++;
        }
        return len;
    }
};