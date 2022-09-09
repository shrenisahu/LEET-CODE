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
             map<int, map<int, vector< int>>> memo;
            int currCol = 0;
            int currLevel = 0;
            vector<vector < int>> ans;
            Traverse(root, 0, 0,memo);

            for (auto i: memo)
            {
                int col = i.first;
                vector<int> temp;

                map<int, vector < int>> cache = i.second;
                for (auto j: cache)
                {
                    int currLevel = j.first;
                    vector<int> arr = j.second;
                    sort(arr.begin(), arr.end());
                    for (auto k: arr)
                    {
                        temp.push_back(k);
                    }
                }
                ans.push_back(temp);
            }

            return ans;
        }

    void Traverse(TreeNode *root, int currCol, int currLevel,map<int, map<int, vector< int>>> &memo)
    {

        if (root == NULL)
            return;

        map<int, vector < int>> temp = memo[currCol];
        vector<int> arr = temp[currLevel];
        memo[currCol][currLevel].push_back(root->val);
        
        Traverse(root->left, currCol - 1, currLevel + 1,memo);
        Traverse(root->right, currCol + 1, currLevel + 1,memo);

        return;
    }
};