#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> 
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;

typedef tree<
pair<int,int>,
null_type,
less<pair<int,int>>,
rb_tree_tag,
tree_order_statistics_node_update>
pbds;


class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int> ans , ar1 , ar2;
        pbds s1 , s2;
        ar1.push_back(nums[0]);
        ar2.push_back(nums[1]);
        s1.insert({nums[0] , 0});
        s2.insert({nums[1] , 1});
        for(int i=2;i<nums.size();i++){
            int x=nums[i];
              int gc1 = s1.size() - s1.order_of_key({x+1, -1});
            int gc2 = s2.size() - s2.order_of_key({x+1, -1});
            if(gc1>gc2){
                ar1.push_back(x);
                s1.insert({x,i});
            }
           
            if(gc2>gc1){
                ar2.push_back(x);
                s2.insert({x,i});
            }

             if(gc1==gc2){
                if(ar1.size()>ar2.size()) {
                    ar2.push_back(x);
                s2.insert({x,i});continue;
                }
                ar1.push_back(x);
                s1.insert({x,i});
            }
        }
        
for(auto it: ar2) ar1.push_back(it);
return ar1;
        //return ans;
    }
};