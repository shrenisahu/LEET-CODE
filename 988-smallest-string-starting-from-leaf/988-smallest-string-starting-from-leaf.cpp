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
    string maxStr = "zzzzzzzzzz";
    public:
        string smallestFromLeaf(TreeNode *root)
        {

            string currStr = "";
            Solve(root, currStr);
            return maxStr;
        }

    void Solve(TreeNode *root, string currStr)
    {

        if(root==NULL)
            return ;
        if (root->left == NULL && root->right == NULL)
        {
            char currChar=root->val+'a';
            currStr = currChar + currStr;

            // cout << currStr << " ";
            maxStr = min(maxStr, currStr);
            return;
        }
char currChar=root->val+'a';
        
        Solve(root->left, currChar + currStr);
        Solve(root->right, currChar + currStr);
    }
};