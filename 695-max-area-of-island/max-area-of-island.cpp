class Solution {
public:

void dfs(vector<vector<int>> &grid , int i , int j , int &tempans){
    grid[i][j]=-1;
    tempans++;
    int m=grid.size() , n=grid[0].size();
    if(i+1<m && grid[i+1][j]==1) dfs(grid ,i+1 , j ,tempans);
    if(i-1>=0 && grid[i-1][j]==1) dfs(grid ,i-1 , j , tempans);
    if(j+1<n && grid[i][j+1]==1) dfs(grid , i , j+1 , tempans);
    if(j-1>=0 && grid[i][j-1]==1) dfs(grid , i , j-1 , tempans);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m=grid.size() , n=grid[0].size();int ans=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0) continue;
                int tempans=0;
                dfs(grid , i , j , tempans);
ans=max(ans ,tempans);
            }
        }return ans;
    }
};