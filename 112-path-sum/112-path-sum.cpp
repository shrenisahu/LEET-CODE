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
            return Solve(root, 0, targetSum);
        }

    bool Solve(TreeNode *root, int currSum, int targetSum)
    {
        if (root == NULL)
            return false;

        if (root->left == NULL && root->right == NULL && currSum + root->val == targetSum)
        {

            cout << "here";
            return true;
        }

        return Solve(root->left, currSum + root->val, targetSum) || Solve(root->right, currSum + root->val, targetSum);
    }
};