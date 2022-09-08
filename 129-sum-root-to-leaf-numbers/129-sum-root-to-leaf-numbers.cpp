/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int sumNumbers(TreeNode *root) {
            int currSum=0;
            if(root==NULL) return 0;
            Solve(root,0,currSum);
            return currSum;
        }

    void Solve(TreeNode *root, int currStr, int &currSum)
    {

        if (root->left == NULL && root->right == NULL)
        {
            currStr = currStr *10 + root->val;
            currSum += currStr;
            return;
        }
        currStr = currStr *10 + root->val;
        if (root->left)
            Solve(root->left, currStr, currSum);
        if (root->right)
            Solve(root->right, currStr, currSum);
    }
};