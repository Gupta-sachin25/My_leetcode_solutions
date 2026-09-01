class Solution {
public:
bool check(vector<int> &temp , vector<int> &kb){

    for(int i=31;i>=0;i--) {
        if(kb[i]==1 && temp[i]==0) return false;
        if(kb[i]==0 && temp[i]>0) return true;
    }
    return true;

}

    int minimumSubarrayLength(vector<int>& v, int k) {
        int n=v.size();
        if(k==0) return 1;

        vector<vector<int>> dp(32 , vector<int> (n+1 , 0));
        for(int i=0;i<n;i++){
            int curc=i+1;
            int num=v[i];
            for(int j=0;j<32;j++){
                dp[j][curc]=num&1;
                num/=2;
                if(num==0) break;
            }
        }
        

        for(int i=0;i<32;i++){
            for(int j=1;j<=n;j++) dp[i][j]+=dp[i][j-1];
        }

        vector<int> kb(32,0);
        int temp=k;
        for(int i=0;i<32 && temp>0;i++){
            kb[i]=temp&1;
            temp/=2;
            if(temp==0) break;
        }

        int ans=n+1;
        int i=1;
        for(int j=1;j<=n;j++){
            vector<int> temp;
            for(int r=0;r<32;r++){
                temp.push_back(dp[r][j] -dp[r][i-1]);
            }
            if(check(temp , kb)){
                ans=min(ans , j-i+1);
                while(i<=j){
                    vector<int> temp;
                    for(int r=0;r<32;r++){
                        temp.push_back(dp[r][j] -dp[r][i]);
                    }
                    if(check(temp,kb)){
                        i++;
                        ans=min(ans,j-i+1);
                    }
                    else break;
                }
            }

        }

        return ans==n+1 ? -1 : ans;
    }
};