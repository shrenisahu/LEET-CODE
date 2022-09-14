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

        bool isPalindrome(unordered_map<int, int> memo)
        {
            int oddCount = 0;
            for (auto it: memo)
            {
                if (it.second % 2 == 1)
                    oddCount++;

                if (oddCount == 2)
                    return false;
            }
            return true;
        }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int validPathCount = 0;
        unordered_map<int, int> memo;
        Traverse(root, memo, validPathCount);
        return validPathCount;
    }

    void Traverse(TreeNode *root, unordered_map<int, int> &memo, int &validPathCount)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            memo[root->val]++;
            if (isPalindrome(memo))
                validPathCount++;
            
            memo[root->val]--;
            if (memo[root->val] == 0)
                return;
        }

        memo[root->val]++;
        Traverse(root->left, memo, validPathCount);

        Traverse(root->right, memo, validPathCount);
        memo[root->val]--;
        if (memo[root->val] == 0)
            memo.erase(root->val);
        return;
    }
};