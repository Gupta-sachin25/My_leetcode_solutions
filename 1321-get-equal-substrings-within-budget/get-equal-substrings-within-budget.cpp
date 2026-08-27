class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        vector<int> cost;
        for(int i=0;i<s.size();i++) cost.push_back(abs(s[i]-t[i]));
        int i=0;
        int len=0;
        int j=0;
        int sum=0;
        while(j<s.size()){
sum+=cost[j];
while(sum>maxCost){
    sum-=cost[i];i++;
}

len=max(len , j-i+1);
j++;
        }
        return len;
    }
};