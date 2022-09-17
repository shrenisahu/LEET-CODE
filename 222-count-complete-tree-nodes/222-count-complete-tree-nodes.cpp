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
    int leftHeight = 0;
    int countLeaf = 0;
    TreeNode *leftMostNode = NULL;
    int mainIndex = 0;

    public:
        int countNodes(TreeNode *root)
        {
            if (root == NULL)
                return 0;

            findLeftHeight(root);
            Traverse(root, 1, 1);
            cout << mainIndex << endl;
            return mainIndex;
        }
    void Traverse(TreeNode *root, int currLevel, int currIndex)
    {

        if (root == NULL)
            return;

        if (currLevel == leftHeight)
        {

            mainIndex = max(mainIndex,currIndex);
            // cout << "mainIndex" << mainIndex << "  ";
            return;
        }
        if (root->right)
            Traverse(root->right, currLevel + 1, 2 *currIndex + 1);
        if (root->left)
            Traverse(root->left, currLevel + 1, 2 *currIndex + 0);
    }

    void findLeftHeight(TreeNode *root)
    {

        leftHeight++;
        if (root->left == NULL && root->right == NULL)
        {
            leftMostNode = root;
            return;
        }
        findLeftHeight(root->left);

        return;
    }
};