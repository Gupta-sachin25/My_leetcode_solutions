class Solution {
public:
int mod=1e9+7;
    int divisibleGame(vector<int>& nums) {
        if(nums.size() == accumulate(nums.begin(), nums.end(), 0))
        return 1000000005;
        set<int> st;
        for(auto x: nums){
            for(int i=2;i*i<=x;i++){
                if(x%i==0){
                    st.insert(i);
                    while(x%i==0) x/=i;
                }
            }
            if(x>1) st.insert(x);
        }

        vector<int> prime(st.begin(), st.end());

        long long mxa=LLONG_MIN,mink=2;

        for(auto x: prime){
            long long cur=0,mx=LLONG_MIN;
            for(int j=0;j<nums.size();j++){
                if(nums[j]%x==0) cur+=nums[j];
                else cur-=nums[j];

                mx=max(mx,cur);
                cur=max(cur,0LL);
            }

            if(mx>mxa){
                mxa=mx;
                mink=x;
            }
        }

        return ((mxa%mod)*mink)%mod;
    }
};