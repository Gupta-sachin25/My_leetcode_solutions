class Solution {
public:
    int maximumLengthSubstring(string s) {
        int len=0;
        int l=0 , r=0;
        unordered_map<char , int> mp;
        while(r<s.size()){
            mp[s[r]]++;
                while(mp[s[r]]>2){
                    mp[s[l]]--;
                    l++;
                
            }  len=max(len , r-l+1);r++;
           
        } return len;
    }
};