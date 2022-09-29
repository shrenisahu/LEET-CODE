/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
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
        TreeNode* sortedListToBST(ListNode *head)
        {

            return buildtree(head);
        }

    TreeNode* buildtree(ListNode *head)
    {

        if (head == NULL)
            return NULL;
        if (head->next == NULL)
        {

            TreeNode *temp = new TreeNode(head->val);
            return temp;
        }

        ListNode *prev = NULL;
        ListNode *fastPtr = head;
        ListNode *slowPtr = head;

        while (fastPtr != NULL && fastPtr->next)

        {
            prev = slowPtr;
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next->next;
        }
        TreeNode *root = new TreeNode(slowPtr->val);

        ListNode *after = slowPtr->next;
        slowPtr->next = NULL;
        prev->next = NULL;

        root->left = buildtree(head);

        root->right = buildtree(after);

        return root;
    }
};