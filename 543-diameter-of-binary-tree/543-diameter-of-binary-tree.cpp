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
    int maxElem=INT_MIN;
    public:
        int diameterOfBinaryTree(TreeNode *root) {
            if(root==NULL)
                return 0;
            Solve(root);
            return maxElem;
            
        }

    void Solve(TreeNode *root)
    {
        if (root == NULL)
            return;
        int lh=findHeight(root->left);
        int rh=findHeight(root->right);
       maxElem=max(maxElem,lh+rh);
        // cout << "for root" << root->val << "  diameter id" << lh+rh << endl;
        Solve(root->left);
        Solve(root->right);
    }

    int findHeight(TreeNode *root)
        {
            if (root == NULL)
                return 0;
            int lh = findHeight(root->left);
            int rh = findHeight(root->right);

            return 1+max(lh , rh);
    }
};