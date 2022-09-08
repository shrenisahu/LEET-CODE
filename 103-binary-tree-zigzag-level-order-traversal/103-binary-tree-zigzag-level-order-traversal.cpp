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
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {

            queue<TreeNode*> que;
            bool flag = true;	// left to right
            vector<vector < int>> ans;
            if (root == NULL)
                return ans;
            que.push(root);
            while (!que.empty())
            {
                int n = que.size();
                vector<int> temp(n);
                for (int i = 0; i < n; i++)
                {
                    TreeNode *currNode = que.front();
                    que.pop();

                    if (flag == false)
                    {

                        temp[n - i - 1] = currNode->val;
                    }
                    else
                    {
                        temp[i] = currNode->val;
                    }
                    if (currNode->left)
                        que.push(currNode->left);
                    if (currNode->right)
                        que.push(currNode->right);
                }
                flag = !flag;

                ans.push_back(temp);
            }
            return ans;
        }
};