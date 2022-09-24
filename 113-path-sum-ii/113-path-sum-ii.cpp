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
    vector<vector < int>> ans;
    public:

        vector<vector < int>> pathSum(TreeNode *root, int targetSum)
        {

            vector<int> temp;
            int currSum = 0;
            Traverse(root, targetSum, currSum, temp);
            return ans;
        }

    void Traverse(TreeNode *root, int targetSum, int currSum, vector<int> temp)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            currSum += root->val;
            temp.push_back(root->val);
             // cout<<currSum<<" ";
            if (currSum == targetSum)
            {
                ans.push_back(temp);
            }
            return;
        }

        currSum += root->val;
        // cout<<currSum<<" ";
        temp.push_back(root->val);
        Traverse(root->left, targetSum, currSum, temp);
        Traverse(root->right, targetSum, currSum, temp);
        return;
    }
};