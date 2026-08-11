class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum=nums[0];
        int n=nums.size();
        if(n==1) return sum+1;
        int ct=1;
        int lst=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==lst+1){
                ct++;
                lst=nums[i];
                sum+=nums[i];
            }
            else break;
        }
      //  if(ct==1) return sum+1;
        ranges::sort(nums);
        cout<<sum;
        
    // auto it=ranges::lower_bound(nums , sum);
    // if(it==nums.end()) return sum;
    // sum++;
    while(ranges::find(nums,sum)!=nums.end()){
        sum++;
        // auto it=ranges::lower_bound(nums , sum);
        // if(it==nums.end()) return sum;
    }
    return sum;
      
    }
};