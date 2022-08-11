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
    bool isValidBST(TreeNode* root) {
        bool flag=true;
        TreeNode *prev=NULL;
        Inorder(root,flag,prev);
        return flag;
    }
    void Inorder(TreeNode *root,bool &flag,TreeNode* &prev)
    {
        if(root==NULL)
            return ;
        
        Inorder(root->left,flag,prev);
        if(prev !=NULL &&  prev->val >= root->val )
        {
            flag=false;
            return ;
        }
        prev=root;
        Inorder(root->right,flag,prev);
        return;
            
    }
   
};