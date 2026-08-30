class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int ans=0;
        vector<int> temp;
        for(int i=0;i<c.size();i++){
            int dif=c[i]-r[i];
            if(dif==0){ans++;continue;}
            temp.push_back(dif);
        }
        ranges::sort(temp);
        for(int i=0 ; i<temp.size() && a>0 ; i++){
            if(a<temp[i]) break;
            a-=temp[i];
            ans++;
            if(a<=0) break;
        }
        return ans;
        
    }
};