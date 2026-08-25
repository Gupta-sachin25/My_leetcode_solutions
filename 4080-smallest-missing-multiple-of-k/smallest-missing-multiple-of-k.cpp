class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
       unordered_map<int,int> mp;
       for(int i=0;i<nums.size();i++) mp[nums[i]]++;int temp=k;
     
        while(mp.find(k) != mp.end()) k+=temp;
        return k;
     
    
    }
};