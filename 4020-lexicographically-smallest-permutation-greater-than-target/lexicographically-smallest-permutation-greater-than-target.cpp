class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        int n=s.size();
        int ind=-1;
        vector<int> cnt(26,0);
        for(auto x: s) cnt[x-'a']++;
        string ans="";
        for(int i=0;i<n;i++){
            
            int cur=t[i];
            for(int k=cur-'a'+1;k<26;k++){
                if(cnt[k]>0) {ind=i; break;}
            }

            if(cnt[cur-'a']>0){
                cnt[cur-'a']--;
            }
            else break;

            
        } 
cout<<ind<<endl;
if(ind==-1) return "";
for(int i=0;i<26;i++) cnt[i]=0;
for(auto x: s) cnt[x-'a']++;

for(int i=0;i<n;i++){
if(i<ind) {ans+=t[i];cnt[t[i]-'a']--;continue;}
if(i==ind){
    for(int k=t[i]-'a'+1;k<26;k++){
        if(cnt[k]){
            cnt[k]--;
            ans+='a'+k;
            break;
        }
    }
}
if(i>ind) break;
}
for(int i=0;i<26;i++){
    int temp=cnt[i];
    while(temp>0){
        ans+='a'+i;
        temp--;
    }
}
return ans;
    }
};