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
        string currStr = "";
    string tree2str(TreeNode *root)
    {
        preOrder(root);

        return currStr;
    }

    void preOrder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }
        currStr += to_string(root->val);
        if (root->left)
        {
            currStr += '(';
            preOrder(root->left);
            currStr += ')';
        }
        if (root->right)
        {
            if (root->left == NULL)
            {
                currStr += "()";
            }

            currStr += '(';
            preOrder(root->right);
            currStr += ')';
        }
    }
};