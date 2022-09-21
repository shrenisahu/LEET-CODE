/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *   TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        TreeNode* deleteNode(TreeNode *root, int key)
        {
            if(root==NULL)
                return NULL;
            if (root->val > key)
                root->left = deleteNode(root->left, key);
            else if (root->val < key)
                root->right = deleteNode(root->right, key);
            else if (root->val == key)
            {
                if (root->left == NULL && root->right == NULL)
                    root = NULL;

                else if (root->left && root->right == NULL)
                {
                    root = root->left;
                }
                else if (root->left == NULL && root->right)
                {
                    root = root->right;
                }
                else
                {
                    TreeNode *substitute = findInorderSuccessror(root);
                    swap(substitute->val, root->val);

                    root->right = deleteNode(root->right, key);
                }
               
            }
             return root;
        }

    TreeNode* findInorderSuccessror(TreeNode *root)
    {
        TreeNode *curr = root->right;

        while (curr->left != NULL)
        {
            curr = curr->left;
        }
        return curr;
    }
};