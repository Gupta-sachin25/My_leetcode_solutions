class Solution {
public:
bool dfs(int clr , vector<int> &col , vector<vector<int>> &v,int num){
    if(col[num]==-1){col[num]=clr;}
    if(col[num]!=clr) return false;
    for(int i=0;i<v[num].size();i++){
    int nei = v[num][i];
    if(col[nei] == -1){
        if(dfs(!clr, col, v, nei) == false) return false;
    }
    else if(col[nei] == clr){
        return false;
    }
}

    return true;
}
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> colour(n,-1);
       for(int i = 0; i < n; i++){
        if(colour[i] == -1){
            if(dfs(0, colour, graph, i) == false)
                return false;
        }
    }
    return true;

    }
};