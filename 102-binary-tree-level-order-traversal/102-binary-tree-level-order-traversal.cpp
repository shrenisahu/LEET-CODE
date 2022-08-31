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
        vector<vector < int>> levelOrder(TreeNode *root)
        {

            queue<TreeNode*> que;
            vector<vector < int>> ans;
            if(root==NULL) return ans;
            que.push(root);

            while (!que.empty())
            {

                int size = que.size();
                vector<int> temp;
                for (int i = 0; i < size; i++)
                {
                    TreeNode *currNode = que.front();
                    que.pop();
                    temp.push_back(currNode->val);
                    if (currNode->left != NULL)
                        que.push(currNode->left);
                    if (currNode->right != NULL)
                        que.push(currNode->right);
                }
                ans.push_back(temp);
            }
            return ans;
        }
};