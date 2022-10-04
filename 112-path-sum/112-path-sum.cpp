/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        bool hasPathSum(TreeNode *root, int targetSum)
        {
            if (root == NULL)
                return false;
            return Traverse(root, targetSum, 0);
        }

    bool Traverse(TreeNode *root, int target, int currSum)
    {
       if(root==NULL)
           return false;
        if(root->left==NULL && root->right==NULL)
        {
            currSum+=root->val;
            if(currSum==target)
                return true;
        }
            
            bool leftAns=Traverse(root->left,target,currSum+root->val);
            bool rightAns=Traverse(root->right,target,currSum+root->val);
            
            return leftAns||rightAns;
        
    }
};