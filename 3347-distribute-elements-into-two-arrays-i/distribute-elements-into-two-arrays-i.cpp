class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ar1 = {nums[0]} , ar2={nums[1]};
        for(int i=2;i<nums.size();i++){
            if(ar1.back()>ar2.back()){
                ar1.push_back(nums[i]);
                continue;
            }
            ar2.push_back(nums[i]);
        }
        for(auto it: ar2) ar1.push_back(it);
        return ar1;
    }
};