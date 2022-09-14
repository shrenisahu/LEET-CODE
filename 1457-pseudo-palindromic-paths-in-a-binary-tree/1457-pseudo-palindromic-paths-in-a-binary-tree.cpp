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
// 10
// TC:O(N)
class Solution
{
    public:

        bool isPalindrome(vector<int>&cache)
        {
            int oddCount = 0;
            for (auto it: cache)
            {
                if (it % 2 == 1)
                    oddCount++;

                if (oddCount == 2)
                    return false;
            }
            return true;
        }
    int pseudoPalindromicPaths(TreeNode *root)
    {
        int validPathCount = 0;
        vector<int>cache(10,0);
       
        Traverse(root, validPathCount,cache);
        return validPathCount;
    }

    void Traverse(TreeNode *root,  int &validPathCount,  vector<int>cache)
    {
        if (root == NULL)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            cache[root->val]++;
            if (isPalindrome(cache))
                validPathCount++;
            
            cache[root->val]--;

        }

        cache[root->val]++;
        Traverse(root->left, validPathCount,cache);

        Traverse(root->right, validPathCount,cache);
        cache[root->val]--;
      
        return;
    }
};