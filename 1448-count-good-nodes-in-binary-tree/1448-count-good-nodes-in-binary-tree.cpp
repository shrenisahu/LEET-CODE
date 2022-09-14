/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        int ans = 0;

    int goodNodes(TreeNode *root)
    {

        if (root == NULL)
            return 0;

        int maxValue = INT_MIN;
        preOrder(root, maxValue);
        return ans;
    }

    void preOrder(TreeNode *root, int maxValue)
    {
        if (root == NULL)
            return;
        maxValue = max(maxValue, root->val);
        if (root->val >= maxValue)
            ans++;
        preOrder(root->left, maxValue);
        preOrder(root->right, maxValue);
    }
};