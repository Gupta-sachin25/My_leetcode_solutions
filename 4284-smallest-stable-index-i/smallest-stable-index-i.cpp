class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int ans=0;int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int num=nums[i];
            int maxi=INT_MIN , mini=INT_MAX;
            for(int j=0;j<n;j++){
                if(j<=i) maxi=max(maxi , nums[j]);
                if(j>=i && j<n){
                    mini=min(mini , nums[j]);
                }
            }
            cout<<maxi<<" "<<mini<<endl;
            if(maxi-mini<=k) return i;

        }
return -1;
    }
};