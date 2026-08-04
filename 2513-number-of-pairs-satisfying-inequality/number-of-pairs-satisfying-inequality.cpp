class Solution {
public:
int dif;
long long ans;

void mergesort(int l, int r, vector<int>& nums){
    if(l>=r) {return;}
    int mid=(l+r)/2;

    mergesort(l , mid , nums);
    mergesort(mid+1 , r , nums);

    vector<int> lf , ri;
    for(int i=l;i<=r;i++){
       if(i<=mid){
        lf.push_back(nums[i]);
        int val=nums[i]-dif;
        auto it = lower_bound(nums.begin()+mid+1, nums.begin()+r+1, val);
        int idx = it - nums.begin();
        ans += r - idx + 1;
       }
       else ri.push_back(nums[i]);
    }

    int i=0,j=0,k=l;

    while(i<lf.size() && j<ri.size()){
        if(lf[i]<=ri[j]){
            nums[k++]=lf[i++];
        }
        else{
            nums[k++]=ri[j++];
        }
    }

    while(i<lf.size()){
        nums[k++]=lf[i++];
    }

    while(j<ri.size()){
        nums[k++]=ri[j++];
    }
}

    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        vector<int> rew(nums1.size());
        dif=diff;
        ans=0;

        for(int i=0;i<nums1.size();i++){
            rew[i]=nums1[i]-nums2[i];
        }

        mergesort(0, nums1.size()-1, rew);

        return ans;
    }
};