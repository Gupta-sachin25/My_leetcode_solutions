/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

int ctn(TreeNode * root){
  if(root==nullptr) return 0;
        int ctr=1 , ctl=1;
        TreeNode *temp=root;
        while(temp->right!=nullptr){ctr++;temp=temp->right;}
        temp=root;
        while(temp->left !=nullptr){ctl++;temp=temp->left;}
        if(ctr==ctl){
            return ((1<<ctr)-1);
        }
        return 1+ctn(root->left)+ctn(root->right);
}
    int countNodes(TreeNode* root) {
      
        return ctn(root);
        
    }
};