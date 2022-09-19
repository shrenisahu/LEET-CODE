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
        TreeNode* constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
        {
            unordered_map<int, int> mpp;

            for (int i = 0; i < postorder.size(); i++)
            {
                mpp[postorder[i]] = i;
            }
            int preIndex = 0;
            return build(preIndex, 0, postorder.size() - 1, preorder, postorder, mpp);
        }

    TreeNode* build(int &preIndex, int postStart, int postEnd, vector<int> &preorder, vector<int> &postorder, unordered_map< int, int> mpp)

    {

        if (postStart == postEnd)
        {
            TreeNode *node = new TreeNode(preorder[preIndex]);
            preIndex++;
            return node;
        }
        if(postStart  >postEnd)
            return NULL;
       if(preIndex >=preorder.size())
           return NULL;
       
        int currElem = preorder[preIndex];

        TreeNode *root = new TreeNode(currElem);
       
        preIndex++;
        int newNode = preorder[preIndex];
        int pos = mpp[newNode];

        root->left = build(preIndex, postStart, pos, preorder, postorder, mpp);
        root->right = build(preIndex, pos + 1, postEnd - 1, preorder, postorder, mpp);

        return root;
    }
};