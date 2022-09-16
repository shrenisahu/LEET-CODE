/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    int count=0;
public:
    int countNodes(TreeNode* root) {
        Traverse(root);
        return count;
    }
    
    void Traverse(TreeNode *root)
    {
        if(root==NULL)
            return ;
        count++;
        Traverse(root->left);
        Traverse(root->right);
        return ;
    }
};