class Solution { 
public: 
    int maxProduct(vector<int>& nums) { 
        int n=nums.size(); 
        if(n==1) return nums[0]; 
        if(n==2){ 
            return max({nums[0] , nums[0]*nums[1] , nums[1]}); 
        } 
       int i=0 , j=0; 
       int ans=INT_MIN; 
       int pro=1; 
       while(j<n){ 
        if(nums[j]==0){ 
            ans=max(ans,0); 
            j++; 
            continue; 
        } 
        i=j; 
        int first=n+1 , last=i-1; 
        int ct=0; 
        int pro=1; 
        while(j<n && nums[j]!=0){ 
            if(nums[j]<0){ 
                ct++; 
                first=min(first , j); 
                last=max(last,j); 
            } 
            pro=pro*nums[j]; 
            j++; 
        } 
        if(ct%2==0){ 
            ans=max(ans , pro); 
            continue; 
        } 
        int pro1=1 , pro2=1; 
        for(int k=i;k<=first;k++) pro1=pro1*nums[k]; 
        for(int k=last;k<j;k++) pro2=pro2*nums[k]; 
        if(first+1<j) ans=max(ans , pro/pro1); 
        if(last>i) ans=max(ans , pro/pro2); 
       } 
       return ans; 
    } 
};