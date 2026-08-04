class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        vector<int> ans;
        int si=nums[0]+1;
        for(int i=1;i<nums.size();i++){
            while(si<nums[i]){
                ans.push_back(si);
                si++;
            }
            si++;
    }
    return ans;
    }
};