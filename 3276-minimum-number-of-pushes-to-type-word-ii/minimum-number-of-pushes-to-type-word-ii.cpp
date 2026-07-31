class Solution {
public:
    int minimumPushes(string word) {
       vector<int> freq(26 , 0);
for(auto x: word) freq[x-'a']++;
sort(freq.rbegin() , freq.rend());
int ans=0;
for(int i=0;i<26;i++){
    if(i<8){
        ans+=freq[i];continue;
    }
    if(i<16){
        ans+=2*freq[i];continue;
    }
    if(i<24){
        ans+=3*freq[i];continue;
    }
    ans+=4*freq[i];
}
return ans; 
    }
};