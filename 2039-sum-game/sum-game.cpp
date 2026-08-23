class Solution {
public:
    bool sumGame(string num) {int n=num.size();
        int suml=0 , sumr=0 , ctl=0 , ctr=0;
        for(int i=0;i<n;i++){
            if(i<n/2){
                if(num[i]>='0' && num[i]<='9') suml+=num[i]-'0';
                else ctl++;
            continue;}
            if(num[i]>='0' && num[i]<='9') sumr+=num[i]-'0';
                else ctr++;
        }
        if(suml == sumr && ctr==ctl) return false;
        if((suml>=sumr && ctl>=ctr) || (suml<=sumr && ctr>=ctl)) return true;


        int rem=max(suml , sumr)-min(suml , sumr);
        if(abs(ctl-ctr)%2!=0) return true;

        int dif=abs(ctl-ctr)/2;
        if(rem==9*dif) return false;



        return true;

    }
};