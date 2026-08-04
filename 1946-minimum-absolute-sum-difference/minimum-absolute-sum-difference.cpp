class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        long long sum=0;int n=nums1.size();
        for(int i=0;i<nums1.size();i++){
            sum+=abs(nums1[i]- nums2[i]);
        }
        vector<int> temp=nums1;
        int ans=0;
        sort(nums1.begin() , nums1.end());
        for(int i=0;i<nums1.size();i++){
            auto it = lower_bound(nums1.begin() , nums1.end() , nums2[i] )-nums1.begin();
            if(it==0){
                ans=max(ans , abs(temp[i]-nums2[i]) - abs(nums1[0] - nums2[i]));
                continue;
            }
            if(it==nums2.size()){
                ans=max(ans , abs(temp[i]-nums2[i]) - abs(nums1[n-1] - nums2[i]));
                continue;
            }
            ans=max(ans , abs(temp[i]-nums2[i]) - abs(nums1[it] - nums2[i]));
            ans=max(ans , abs(temp[i]-nums2[i]) - abs(nums1[it-1] - nums2[i]));
        }
        return (sum-ans)%1000000007;
    }
};