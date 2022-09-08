/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *  int val;
 *  TreeNode * left;
 *  TreeNode * right;
 *  TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<vector < int>> zigzagLevelOrder(TreeNode *root)
        {

            queue<TreeNode*> que;
            bool flag = false;
            vector<vector < int>> ans;
            if(root==NULL)
                return ans;
            que.push(root);
            while (!que.empty())
            {
                int n = que.size();
                vector<int> temp;
                for (int i = 0; i < n; i++)
                {
                    TreeNode *currNode = que.front();
                    que.pop();
                    temp.push_back(currNode->val);
                    if (currNode->left)
                        que.push(currNode->left);
                    if (currNode->right)
                        que.push(currNode->right);
                }
                flag = !flag;
                if (flag == false)
                    reverse(temp.begin(), temp.end());
                ans.push_back(temp);
            }
            return ans;
        }
};