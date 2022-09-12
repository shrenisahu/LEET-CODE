/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *   int val;
 *   TreeNode * left;
 *   TreeNode * right;
 *   TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    public:
        TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {

           return lowestCommonAncestor2(root,p,q);
        }
    
     TreeNode* lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
        {

            if (root == NULL)
                return NULL;

            if (root->val == p->val || root->val == q->val)
                return root;

            TreeNode *leftAns = lowestCommonAncestor2(root->left, p, q);
            TreeNode *rightAns = lowestCommonAncestor2(root->right, p, q);

            if (leftAns != NULL && rightAns != NULL)
                return root;

            if (leftAns != NULL)
                return leftAns;

            if ( rightAns != NULL)
                return rightAns;
            
            
            return NULL;
        }
};