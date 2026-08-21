class Solution {
public:
int solve(vector<int> &v , int dif)
{
    int ans=0;
    for(int i=0;i<v.size();i++){
        auto it = lower_bound(v.begin() , v.end() , v[i]+dif+1)-v.begin();
        ans+=it-1-i;
    }
    return ans;

}
    int smallestDistancePair(vector<int>& nums, int k) {
     sort(nums.begin() , nums.end());
     int lo=0 , hi=nums[nums.size()-1]-nums[0];
     while(hi>lo){
        int mid=(hi+lo)/2;
        if(solve(nums , mid)>=k){
            hi=mid;
        }
        else lo=mid+1;
     }   
     return hi;
    }
};