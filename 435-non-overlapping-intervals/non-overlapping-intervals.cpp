class Solution {
public:
static bool cmp(vector<int> &a , vector<int> &b){
    if(a[1]!=b[1]) return a[1]<b[1];
    return a[0]<b[0];
}
    int eraseOverlapIntervals(vector<vector<int>>& v) {
       sort(v.begin() , v.end() , cmp);
       int n = v.size();
       int si=v[0][0] , ei=v[0][1] , ans=0;
       for(int i=1;i<n;i++){
        if(v[i][0]>=ei){
            ei=v[i][1];
            si=v[i][0];
            continue;
        }
        ans++;
       }
       return ans;
    }
};