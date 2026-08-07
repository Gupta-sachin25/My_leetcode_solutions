class Solution {
public:
    vector<int> par;
    vector<int> rank;

    int findpar(int x) {
        if (x == par[x])
            return x;
        return par[x] = findpar(par[x]);
    }
    void unite(int i, int j) {
        int pi = findpar(i);
        int pj = findpar(j);
        if (pi == pj)
            return;
        if (rank[pi] < rank[pj]) {
            par[pi] = pj;
        } else if (rank[pi] > rank[pj]) {
            par[pj] = pi;
        } else {
            par[pi] = pj;
            rank[pj]++;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& ac) {
        int n = ac.size();
        vector<vector<string>> ans;
        par.resize(n + 1, 0);
        rank.resize(n + 1, 0);
        for (int i = 0; i <= n; i++)
            par[i] = i;
        unordered_map<string, int> mp;
        for (int i = 0; i < n; i++) {
           // ans[i].push_back(ac[i][1]);
            for (int j = 1; j < ac[i].size(); j++) {
                string& s = ac[i][j];
                if (mp.find(s) == mp.end()) {
                    mp[s] = i;
                } else {
                    unite(i, mp[s]);
                }
            }
        }

        unordered_map<int , vector<string>> merged;
        for(auto &it: mp){
            string s=it.first ;int id=it.second;
            id=findpar(id);
            merged[id].push_back(s); 
        }

        for(auto &it: merged){
              int parent = it.first;

            sort(it.second.begin(), it.second.end());

            vector<string> temp;

            temp.push_back(ac[parent][0]);

            for (string &email : it.second)
                temp.push_back(email);

            ans.push_back(temp);
        }



        return ans;
    }
};