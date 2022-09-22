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

    unordered_map<int, int> mpp;
    public:
        TreeNode* bstFromPreorder(vector<int> &preorder)
        {
            int n = preorder.size();
            vector<int> inOrder = preorder;
            sort(inOrder.begin(), inOrder.end());

            for (int i = 0; i < n; i++)
            {
                mpp[inOrder[i]] = i;
            }
            int preIndex = 0;
            return construct(preIndex, preorder, inOrder, 0, n - 1);
        }

    TreeNode* construct(int &preIndex, vector<int> &preorder, vector<int> &inOrder, int start, int end)

    {

        if (start > end)
            return NULL;

        int currVal = preorder[preIndex];
        TreeNode *root = new TreeNode(currVal);
        int pos = mpp[currVal];
        preIndex++;
        root->left = construct(preIndex, preorder, inOrder, start, pos - 1);
        
        root->right = construct(preIndex, preorder, inOrder, pos + 1, end);

        return root;
    }
};