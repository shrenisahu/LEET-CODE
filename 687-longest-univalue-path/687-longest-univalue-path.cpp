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
        int maxAns = 0;
    int longestUnivaluePath(TreeNode *root)
    {
        if (root == NULL)
            return 0;
        
        Traverse(root);
        return maxAns;

        
    }

    void Traverse(TreeNode *root)
    {
        if (root == NULL)
            return;
        int ans=Solve(root);
        Traverse(root->left);
        Traverse(root->right);
        return;
    }
    int Solve(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        int lh = findVal(root->left, root->val);
        int rh = findVal(root->right, root->val);
        maxAns = max(maxAns,  lh + rh);
        
        return 0;
    }

    int findVal(TreeNode *root, int val)
    {
        if (root == NULL || root->val != val)
            return 0;

        int lh = findVal(root->left, val);
        int rh = findVal(root->right, val);

        return 1 + max(lh, rh);
    }
};