class Solution {
public:
    int countRatioSubarrays(vector<int>& nums, int a, int b) {
        double val = a/(b*1.0);
        int ans=0;
        for(int i=0;i<nums.size();i++){int cto=0 , cte=0;
            for(int j=i;j<nums.size();j++){
                if(nums[j]%2) cto++;
                else cte++;
double valid=INT_MAX;
              if(cto)   valid= cte/(cto*1.0);
              //  cout<<valid<<endl;
                if(valid<=val) ans++;
            }
        }

return ans;

        return 0;
    }
};