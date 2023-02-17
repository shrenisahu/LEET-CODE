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
        vector<int> arr;
    void Traverse(TreeNode *root)
    {
        if (root == NULL)
            return;

        arr.push_back(root->val);

        Traverse(root->left);
        Traverse(root->right);
    }

    int minDiffInBST(TreeNode *root)
    {

        Traverse(root);
        sort(arr.begin(),arr.end());
        int n=arr.size();
        int diff=INT_MAX;
        for(int i=0;i<n-1;i++)
        {
            int temp=abs(arr[i]-arr[i+1]);
            diff=min(diff,temp);
            
        }
        

        return diff;
    }
};