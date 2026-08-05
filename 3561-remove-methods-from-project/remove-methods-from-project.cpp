class Solution {
public:

void dfs(vector<vector<int>> &adj , int node , vector<int> &vis){
    vis[node]=1;
    for(auto x: adj[node]){
        if(!vis[x]) dfs(adj , x , vis);
    }
    return;
}
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& in) {
        
        vector<vector<int>> adj(n);
        for(int i=0;i<in.size();i++){
            adj[in[i][0]].push_back(in[i][1]);}
        
vector<int> vis(n , 0);
vis[k]=1;
dfs(adj , k , vis);

// int sum=accumulate(vis.begin() , vis.end(),0);
// cout<<sum<<" ";

/// main logic here

vector<int> ans;
for(int i=0;i<in.size();i++){
    if(vis[in[i][0]]==0 && vis[in[i][1]]==1){
        for(int i=0;i<n;i++) ans.push_back(i);
        return ans;
    }
}
for(int i=0;i<n;i++) if(vis[i]==0) ans.push_back(i);
return ans;


    }
};