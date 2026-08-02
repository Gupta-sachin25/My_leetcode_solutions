class Solution {
public:
long long func(int a , int b){
    return ((a*1ll*b) / ((__gcd(a,b) *1ll* __gcd(a,b))));
}
    long long maxPairStrength(vector<int>& nums) {long long ans=-1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1 ; j<nums.size();j++){
ans=max(ans , func(nums[i] ,nums[j]));
            }
        }
        return ans;
    }
};