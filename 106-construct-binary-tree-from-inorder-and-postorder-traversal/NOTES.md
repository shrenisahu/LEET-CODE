/**
*Definition for a binary tree node.
*struct TreeNode {
*    int val;
*    TreeNode * left;
*    TreeNode * right;
*    TreeNode() : val(0), left(nullptr), right(nullptr) {}
*    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
*};
*/
class Solution
{
public:
TreeNode* buildTree(vector<int> &inorder, vector<int> &postorder)
{
int n = postorder.size();
unordered_map<int, int> mpp;
​
for (int i = 0; i < n; i++)
{
mpp[inorder[i]] = i;
}
​
return build(0, n - 1, 0, n - 1,postorder ,inorder,mpp);
}
​
TreeNode* build(int postStart, int postEnd, int inStart, int inEnd, vector<int> &postorder, vector<int> &inorder, unordered_map< int, int> &mpp)
​
{
​
if (postStart > postEnd || inStart > inEnd)
return NULL;
​
int currElem = postorder[postEnd];
int pos = inorder[currElem];
int elemRightOFInorder = inEnd - pos;
TreeNode *currNode = new TreeNode(currElem);
currNode->left = build(postStart, postEnd - elemRightOFInorder - 1, inStart, pos - 1, postorder, inorder, mpp);
​
currNode->right = build(postEnd - elemRightOFInorder, postEnd - 1, pos + 1, inEnd, inorder, postorder, mpp);
​
return currNode;
}
};