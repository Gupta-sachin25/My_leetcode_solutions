/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
       vector<int> ans , lmaxi;
       ListNode *temp=head->next  ;
       ListNode *prev=head;
       int ind=1;
       while(temp && temp->next){
            if((temp->val) >( temp->next->val) && (temp->val )>(prev->val)) 
            lmaxi.push_back(ind);
             if((temp->val) <( temp->next->val) && (temp->val )<(prev->val)) 
            lmaxi.push_back(ind);

            ind++;
            prev=prev->next;
            temp=temp->next;
       }
       int minid = INT_MAX , maxid=INT_MIN;
       if(lmaxi.size()<=1) return {-1,-1};
       maxid=lmaxi[lmaxi.size()-1]-lmaxi[0];

       for(int i=0;i<lmaxi.size()-1;i++){
            minid=min(minid , lmaxi[i+1]-lmaxi[i]);
       }
       return {minid , maxid};
       return ans;
    }
};