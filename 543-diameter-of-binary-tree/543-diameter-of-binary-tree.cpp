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

//TC:O(N*N)  worst case 
class Solution
{
    int maxElem = 0;
    public:
        int diameterOfBinaryTree(TreeNode *root)
        {
            if (root == NULL)
                return 0;
            int ans= findHeight(root);
            return maxElem;
        }

    void Solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxElem = max(maxElem, lh + rh);

        Solve(root->left);
        Solve(root->right);
    }

    int findHeight(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        int lh = findHeight(root->left);
        int rh = findHeight(root->right);
        maxElem = max(maxElem, lh + rh);

        return 1 + max(lh, rh);
    }
};