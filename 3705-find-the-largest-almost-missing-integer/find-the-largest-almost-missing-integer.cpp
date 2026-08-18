class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if(k==nums.size()) return *max_element(nums.begin() , nums.end());
        map<int, int, greater<int>> mp;
for(auto x : nums) mp[x]++;
if(k==1){
    for(auto x: mp){
        if(x.second==1) return x.first;
    }return -1;
}
if(mp[nums[0]] ==1 && mp[nums[nums.size()-1]]==1) return max(nums[0] , nums[nums.size()-1]);
if(mp[nums[0]]==1) return nums[0];
if(mp[nums[nums.size()-1]]==1) return nums[nums.size()-1];
return -1;
    }
};