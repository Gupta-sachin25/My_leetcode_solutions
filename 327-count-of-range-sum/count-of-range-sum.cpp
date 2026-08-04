class Solution {
public:

int lower , upper , ans;

void mergesort(int l , int r , vector<int> &nums){
    if(l==r){
        if (nums[l]>=lower && nums[r]<= upper) {ans++;}
        return ;
    }
    int mid= l+r;
    mid/=2;

    mergesort(l , mid , nums);
    mergesort(mid+1 , r , nums);

    int rsi = mid+1;
    int rei = r;
    
    vector<long long> prf;
    long long sum=0;
    for(long long i= mid+1 ; i<=r ;i++){
        sum+=nums[i];
        prf.push_back(sum);
    }
    sort(prf.begin() , prf.end());
    vector<long long> suf;
    sum=0;
    for(long long i=mid ; i>=l;i--){
        sum+=nums[i];
        suf.push_back(sum);
    }

    for(int i=0;i<suf.size();i++){
        long long val= suf[i];
        auto si= lower_bound(prf.begin() , prf.end() , lower-val)-prf.begin();
       auto sii = lower_bound(prf.begin(), prf.end(), (long long)lower - val);
    auto eii = upper_bound(prf.begin(), prf.end(), (long long)upper - val);

    ans += (eii - sii);
    }



}



    int countRangeSum(vector<int>& nums, int lowerr, int upperr) {
        ans=0;
        lower=lowerr;
        upper = upperr;
        mergesort(0 , nums.size()-1 , nums);
        return ans;
    }
};