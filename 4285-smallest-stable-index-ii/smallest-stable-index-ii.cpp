class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        vector<int> mini(nums.size());
        int n=nums.size();
        for(int i=n-1;i>=0;i--){
            if(i==n-1) {mini[i]=nums[i];continue;}
            mini[i]=min(mini[i+1] , nums[i]);
        }
        int maxi=INT_MIN;
        for(int i=0;i<n;i++){
          //  cout<<mini[i]<<" ";
            maxi=max(maxi , nums[i]);
           // cout<<maxi<<" "<<endl;
            if(maxi-mini[i]<=k) return i;
        }
        return -1;
    }
};