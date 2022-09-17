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
        TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
        {
            int n = inorder.size();
            unordered_map<int, int> mpp;

            for (int i = 0; i < n; i++)
            {
                mpp[inorder[i]] = i;
            }
            int postIndex = n - 1;
            return build(postIndex, 0, n - 1, inorder, postorder, mpp);
        }

    TreeNode* build(int &postIndex, int inStart, int inEnd, vector<int> &inorder, vector<int> &postorder, unordered_map< int, int> &mpp)

    {

        if (postIndex < 0 || inStart > inEnd)
            return NULL;
        int currElem = postorder[postIndex];
        int pos = mpp[currElem];
        TreeNode *currNode = new TreeNode(currElem);
        postIndex--;
        currNode->right = build(postIndex, pos + 1, inEnd, inorder, postorder, mpp);
        currNode->left = build(postIndex, inStart, pos - 1, inorder, postorder, mpp);

        return currNode;
    }
};