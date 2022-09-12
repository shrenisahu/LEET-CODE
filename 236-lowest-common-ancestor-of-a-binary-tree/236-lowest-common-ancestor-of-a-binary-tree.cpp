/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    set<TreeNode*> stt;
    public:
        TreeNode* lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
        {
            stt.insert(p);
            stt.insert(q);
            return lowestCommonAncestor2(root, p, q);
        }

    TreeNode* lowestCommonAncestor2(TreeNode *root, TreeNode *p, TreeNode *q)
    {

        if (root == NULL)
            return NULL;

        if(stt.find(root)!=stt.end())
            return root;

        TreeNode *leftAns = lowestCommonAncestor2(root->left, p, q);
        TreeNode *rightAns = lowestCommonAncestor2(root->right, p, q);

        if (leftAns != NULL && rightAns != NULL)
            return root;

        if (leftAns != NULL)
            return leftAns;

        if (rightAns != NULL)
            return rightAns;

        return NULL;
    }
};