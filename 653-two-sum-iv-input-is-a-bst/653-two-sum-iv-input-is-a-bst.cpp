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
        bool findTarget(TreeNode *root, int k)
        {

            stack<TreeNode*> rightStack;
            stack<TreeNode*> leftStack;

            if (root == NULL)
                return true;

            TreeNode *rightPtr = root;
            TreeNode *leftPtr = root;

            while (leftPtr)
            {
                leftStack.push(leftPtr);
                leftPtr = leftPtr->left;
            }
            while (rightPtr)
            {
                rightStack.push(rightPtr);
                rightPtr = rightPtr->right;
            }

            leftPtr = leftStack.top();
            rightPtr = rightStack.top();

            while (leftPtr != rightPtr)
            {
                int sum = leftPtr->val + rightPtr->val;
                if (sum == k)
                    return true;

                else if (sum < k)
                {
                   	//move left
                    leftStack.pop();
                    leftPtr = leftPtr->right;
                    while (leftPtr)
                    {
                        leftStack.push(leftPtr);
                        leftPtr = leftPtr->left;
                    }
                    leftPtr = leftStack.top();
                }
                else
                {
                    rightStack.pop();
                    rightPtr = rightPtr->left;
                    while (rightPtr)
                    {
                        rightStack.push(rightPtr);
                        rightPtr = rightPtr->right;
                    }
                    rightPtr = rightStack.top();

                   	// move right ptr
                }
            }
            
            return false;
        }
};