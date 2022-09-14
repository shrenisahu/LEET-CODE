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
        bool checkTree(TreeNode *root)
        {

           
            return checkTree1(root);
        }
     bool checkTree1(TreeNode *root)
        {
         if(root==NULL)
             return true;

            // if (root->left == NULL && root->right == NULL)
            //     return true;

            if (root->right && root->left)
                if (root->val != root->right->val + root->left->val)
                    return false;

            if (root->right && root->left==NULL)
                if (root->val != root->right->val)
                    return false;

            if (root->left && root->right==NULL)
                if (root->val != root->left->val)
                    return false;

            bool leftAns = checkTree(root->left);
            bool rightAns = checkTree(root->right);

            return leftAns && rightAns;
        }
};