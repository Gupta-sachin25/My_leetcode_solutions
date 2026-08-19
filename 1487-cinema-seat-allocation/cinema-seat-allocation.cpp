class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& rs) {
        sort(rs.begin() , rs.end());
        unordered_map<int,vector<int>> mp;
        for(auto x: rs){
            mp[x[0]].push_back(x[1]);
        }
        int ans=0;
        for( auto it: mp){
        bool f1=true , f2=true , f3=true;
        vector<int> &v = it.second;
        for(int i=0;i<v.size();i++){
            if(v[i]==2 || v[i]==3) f1=false;
            if(v[i]==4 || v[i]==5){f1=false;f2=false;}
            if(v[i]==6 || v[i]==7){f2=false;f3=false;}
            if(v[i]==8 || v[i]==9){f3=false;}
        }
         if(f1 && f3)
                ans += 2;
            else if(f1 || f2 || f3)
                ans += 1;
      cout<<f1<<" "<<f2<<" "<<f3<<endl;
        }
        ans+=(n-mp.size())*2;
        return ans;
    }
};