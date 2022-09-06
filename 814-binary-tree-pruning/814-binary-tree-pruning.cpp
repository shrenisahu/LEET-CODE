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
    TreeNode* pruneTree(TreeNode* root) {
        if(root==NULL )
            return root;
        
        Solve(root);
        if(root->val==0 && root->left==NULL && root->right==NULL)
            return NULL;
        return root;
        
    }
    
    void Solve(TreeNode *root)
    {
        
        if(root==NULL)
            return ;
        
        bool leftAns=isOnePresent(root->left);
        bool rightAns=isOnePresent(root->right);
        
        if(leftAns==false)
            root->left=NULL;
        if(rightAns==false)
            root->right=NULL;
        
        Solve(root->left);
        Solve(root->right);
    }
    
    bool isOnePresent(TreeNode *root)
    {
        
        
        if(root==NULL)
            return false;
        
        if(root->val)
            return true;
        
        return isOnePresent(root->left) || isOnePresent(root->right);
        
        
    }};