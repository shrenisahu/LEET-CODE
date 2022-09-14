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
        int ans = 0;
    int goodNodes(TreeNode *root)
    {
        priority_queue<int> que;

        if (root == NULL)
            return 0;

        preOrder(root, que);
        return ans;
    }

    void preOrder(TreeNode *root, priority_queue<int> que)
    {
        if (root == NULL)
            return;

        que.push(root->val);
        if (que.top() <= root->val)
            ans++;

        preOrder(root->left, que);
        preOrder(root->right, que);
    }
};