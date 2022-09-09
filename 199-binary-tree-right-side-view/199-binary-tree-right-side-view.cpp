/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        vector<int> rightSideView(TreeNode *root)
        {

            queue<TreeNode*> que;
            vector<int> ans;
            if(root==NULL)
                return ans;
            que.push(root);

            while (!que.empty())
            {

                int n = que.size();

                for (int i = 0; i < n; i++)
                {
                    TreeNode *currNode = que.front();
                    que.pop();

                    if (i == n - 1)
                        ans.push_back(currNode->val);
                    if (currNode->left)
                        que.push(currNode->left);
                    if (currNode->right)
                        que.push(currNode->right);
                }
            }
            return ans;
        }
};