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
    int maxHeight=1;
    public:
        int maxDepth(TreeNode *root)
        {
            int currHeight = 1;
            if (root == NULL)
                return 0;
            Traverse(root, currHeight);
            return maxHeight;

        }

    void Traverse(TreeNode *root, int currHeight)
    {
        if (root == NULL)
            return;

        maxHeight = max(maxHeight, currHeight);
        if (root->left)
            Traverse(root->left, currHeight + 1);

        if (root->right)
            Traverse(root->right, currHeight + 1);
        return;
    }
};