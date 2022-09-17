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
        int countNodes(TreeNode *root)
        {
            int leftHeight = 0, rightheight = 0;
            if (root == NULL)
                return 0;

            return Traverse(root);
        }

    int Traverse(TreeNode *root)
    {
        int height = 0;

        int leftH = findLeftHeight(root);
        int RightH = findRightHeight(root);
        if (leftH == RightH)
            return pow(2, leftH) - 1;

        return 1 + Traverse(root->left) + Traverse(root->right);
    }

    int findLeftHeight(TreeNode *root)
    {

        if (root == NULL)
        {

            return 0;
        }

        return 1 + findLeftHeight(root->left);
    }

    int findRightHeight(TreeNode *root)
    {

        if (root == NULL)
        {

            return 0;
        }

        return 1 + findRightHeight(root->right);
    }
};