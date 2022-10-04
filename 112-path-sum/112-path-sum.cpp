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

            int currSum = 0;
            return Traverse(root, targetSum, currSum);
        }

    bool Traverse(TreeNode *root, int target, int &currSum)
    {
        if (root == NULL)
        {
            return false;
        }
        currSum += root->val;
        if (!root->left && !root->right)

        {

            if (currSum == target)
                return true;
            else
            {
                currSum -= root->val;
                return false;
            }
        }

        bool leftAns = Traverse(root->left, target, currSum);
        bool rightAns = Traverse(root->right, target, currSum);
        currSum -= root->val;

        return leftAns || rightAns;
    }
};