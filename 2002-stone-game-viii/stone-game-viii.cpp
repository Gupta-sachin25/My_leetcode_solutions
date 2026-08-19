class Solution {
public:


    int stoneGameVIII(vector<int>& s) {
        int n=s.size();
      int fin=0;
      for(int i=1;i<n;i++) s[i]+=s[i-1];
      fin=s[n-1];
      for(int i=n-2;i>0;i--){
        fin=max(fin , s[i]-fin);
      }
      return fin;
    }
};