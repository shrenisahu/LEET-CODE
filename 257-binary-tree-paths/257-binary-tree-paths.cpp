/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<string> binaryTreePaths(TreeNode *root)
        {
            vector<string> ans;
            string currStr = "";
            currStr += to_string(root->val);
           
            Path(root, ans, currStr);
            return ans;
        }

    void Path(TreeNode *root, vector<string> &ans, string currStr)
    {
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(currStr);
            return;
        }

        if (root->left != NULL)
        {

            Path(root->left, ans, (currStr +"->"+ to_string(root->left->val) ));
        }
        if (root->right != NULL)
        {

            Path(root->right, ans, (currStr +"->"+ to_string(root->right->val) ));
        }
        return;
    }
};