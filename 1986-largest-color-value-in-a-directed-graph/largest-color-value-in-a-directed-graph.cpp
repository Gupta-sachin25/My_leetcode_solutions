class Solution {
public:
    int largestPathValue(string c, vector<vector<int>>& e) {
        vector<vector<int>> adj(c.size());string s=c;
        vector<int> ind(c.size(),0);
        for(int i=0;i<e.size();i++){
            ind[e[i][1]]++;
            adj[e[i][0]].push_back(e[i][1]);
        }
        vector<vector<int>> dp(c.size(),vector<int> (26,0));

        queue<int> q;  int ct=0;
        int n=c.size();
        for(int i=0;i<c.size();i++ ) if(ind[i]==0){
            q.push(i);
            dp[i][s[i]-'a']=1;
        }
        while(!q.empty()){ct++;
            int u =q.front();
            q.pop();
            for(int i=0;i<adj[u].size();i++){
                int v=adj[u][i];
                for(int j=0;j<26;j++){
                   dp[v][j]=max(dp[v][j],dp[u][j]);
                }
               
                ind[v]--;
                 if(ind[v]==0){
            dp[v][s[v]-'a']++;
            q.push(v);
        }
            }
        }
        if(ct!=n) return -1;

       int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<26;j++){
                ans=max(ans,dp[i][j]);
            }
        }

        return ans;
    }
};