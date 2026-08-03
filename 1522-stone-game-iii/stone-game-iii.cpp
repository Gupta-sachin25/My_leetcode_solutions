class Solution {
public:

// first we will do by 1 d dp 

// think like 

// void solve(){
//     if(ind>=sv.size()) return INT_MAX;
//     if(dp[ind][0] !=INT_MIN) return dp[ind][0];
//     if(dp[ind][1]!=INT_MIN) return dp[ind][1];
//     // take 1
//     dp[ind][turn] = sv[ind] + 

// }

int solve(int ind , vector<int> &dp , vector<int> &s){
    if(ind>=s.size() ) return 0;
    if(dp[ind]!=INT_MIN) return dp[ind];
    int ans=INT_MIN;
    int b=0;
    for(int i=0;i<3 && ind + i < s.size();i++){
        b+=s[i+ind];
        ans=max(ans , b- solve(ind+1+i , dp , s));
    }

    return dp[ind] = ans;

}
    string stoneGameIII(vector<int>& sv) {
     //   vector<vector<int>> dp(sv.size()+1 , vector<int>(2 , INT_MIN));
     vector<int> dp(sv.size(), INT_MIN);
     int an= solve(0 , dp , sv);
     if(an>0) return "Alice";
     if(an==0) return "Tie";
     return "Bob";
    

    }
};