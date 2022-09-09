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
        vector<vector < int>> verticalTraversal(TreeNode *root)
        {
           	
            map<int, map<int, multiset< int>>> memo;
            int currCol = 0;
            int currLevel = 0;
            vector<vector < int>> ans;
            Traverse(root, 0, 0, memo);

            for (auto i: memo)
            {
               
                vector<int> temp;

                map<int, multiset < int>> cache = i.second;
                for (auto j: cache)
                {
                   
                   multiset < int> arr= j.second;
                  
                    for (auto k: arr)
                    {
                        temp.push_back(k);
                    }
                }
                ans.push_back(temp);
            }

            return ans;
        }

    void Traverse(TreeNode *root, int currCol, int currLevel,  map<int, map< int, multiset< int>>> &memo)
    {

        if (root == NULL)
            return;

        

        memo[currCol][currLevel].insert(root->val);

        Traverse(root->left, currCol - 1, currLevel + 1, memo);
        Traverse(root->right, currCol + 1, currLevel + 1, memo);

        return;
    }
};