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
    int maxAns=INT_MIN;
    int maxPathSum(TreeNode* root) {
        Solve(root);
        
        return maxAns;
    }
    
    int Solve(TreeNode *root)
    {
        if(root==NULL )
            return 0;
        
     int leftAns=   max(0,Solve(root->left));
     int rightAns=  max(0, Solve(root->right));
        
        maxAns=max(maxAns,leftAns+rightAns+root->val);
       
        return root->val+max(leftAns,rightAns);
        
        
    }
};