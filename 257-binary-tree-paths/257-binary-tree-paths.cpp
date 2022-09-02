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
        vector<string> binaryTreePaths(TreeNode *root) {
            vector<string>ans;
            string currStr="";
            Traverse(root,ans,currStr);
            return ans;
        }

    void Traverse(TreeNode *root, vector<string> &ans, string currStr)
    {

        if (root == NULL) return;

        if (root->left == NULL && root->right == NULL)
        {
            currStr += to_string(root->val);
            ans.push_back(currStr);
            
        }
        
        else
        {
            currStr+=to_string(root->val)+"->";
        }

        if (root->left)
        {
            Traverse(root->left, ans, currStr);
        }
        if (root->right)
        {
            Traverse(root->right, ans, currStr);
        }
    }
};