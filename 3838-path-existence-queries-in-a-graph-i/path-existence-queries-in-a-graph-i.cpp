class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int k, vector<vector<int>>& q) {
        int id=1;
        vector<int> temp(n,1);
        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]>k) id++;
            temp[i]=id;
        }
        vector<bool> ans(q.size() , false);
            for(int i=0;i<q.size();i++){
if(temp[q[i][0]] == temp[q[i][1]])
    ans[i] = true;
            }
            return ans;
    }
};