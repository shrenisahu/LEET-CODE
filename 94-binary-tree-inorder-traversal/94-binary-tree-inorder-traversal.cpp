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
    vector<int>ans;
        vector<int> inorderTraversal(TreeNode *root) {
            
            Traverse(root);
            return ans;
        }

    void Traverse(TreeNode *root)
    {
        if (root == NULL) return;
        Traverse(root->left);
        ans.push_back(root->val);
        Traverse(root->right);
    }
};