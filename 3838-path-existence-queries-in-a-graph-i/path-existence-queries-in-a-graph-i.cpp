class Solution {
public:
vector<int> par;
vector<int> rank;


    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int k, vector<vector<int>>& q) {

    par.resize(n);
    rank.resize(n);
    for(int i=0;i<n;i++) par[i]=i;
    for(int i=0;i<n;i++) rank[i]=1;

    for(int i=1;i<n;i++){
        if(nums[i]-nums[i-1]<=k) par[i]=par[i-1];
    }

    vector<bool> ans(q.size() , false);
            for(int i=0;i<q.size();i++){
if(par[q[i][0]] == par[q[i][1]])
    ans[i] = true;
            }
            return ans;









        
//         int id=1;
//         vector<int> temp(n,1);
//         for(int i=1;i<n;i++){
//             if(nums[i]-nums[i-1]>k) id++;
//             temp[i]=id;
//         }
//         vector<bool> ans(q.size() , false);
//             for(int i=0;i<q.size();i++){
// if(temp[q[i][0]] == temp[q[i][1]])
//     ans[i] = true;
//             }
//             return ans;
    }
};