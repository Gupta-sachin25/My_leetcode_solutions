class Solution {
public:
    bool checkDivisibility(int n) {
        string s=to_string(n);
        int ans=0;  int p=1;
        for(int i=0;i<s.size();i++) ans+=s[i]-'0' , p*=(s[i]-'0');
        return n%(ans+p)==0;
        
      

    }
};