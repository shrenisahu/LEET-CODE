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
        int widthOfBinaryTree(TreeNode *root)
        {
            return BFS(root);
        }

    int BFS(TreeNode *root)
    {
        if (root == NULL)
            return 0;

        queue<pair<TreeNode*, int>> que;

        int maxWidth = 0;
        que.push({ root,
            0 });

        while (!que.empty())
        {
            int left = 0;
            int right = 0;
            int size = que.size();
            int min = que.front().second;
            for (int i = 0; i < size; i++)
            {

                auto currPair = que.front();
                TreeNode *currNode = currPair.first;
                que.pop();
                int currIndex = currPair.second-min;

               
                if (i == 0)
                    left = currIndex;
                if (i == size - 1)
                    right = currIndex;

                cout << currIndex << "  ";
                if (currNode->left)
                    que.push({ currNode->left,(long long)2 *currIndex + 1 });
                if (currNode->right)
                    que.push({ currNode->right, (long long)2 *currIndex + 2 });
            }
            cout << endl;
            maxWidth = max(maxWidth, right - left + 1);
        }

        return maxWidth;
    }
};