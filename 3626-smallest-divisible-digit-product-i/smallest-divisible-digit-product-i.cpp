class Solution {
public:
int dosum(string &s){
    int pro=1;
    for(int i=0;i<s.size();i++) pro*=(s[i]-'0');
    return pro;
}
    int smallestNumber(int n, int t) {
        string s=to_string(n);
        while(true){
            int sum=0;string s=to_string(n);
            sum=dosum(s);
            if(sum%t==0) return stoi(s);
            n++;
        }
    }
};