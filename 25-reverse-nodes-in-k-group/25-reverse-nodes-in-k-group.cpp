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
class Solution
{
    public:
        ListNode* reverseKGroup(ListNode *head, int k)
        {
            if (k == 1 || head == NULL)
                return head;

            ListNode *check = validate(head, k);

            if (check != NULL)
            {

                ListNode *curr = check;

                ListNode *tempNode = curr->next;
                curr->next = NULL;

                ListNode *reversedList = reverseList(head);
                head->next = reverseKGroup(tempNode, k);
                return reversedList;
            }
            else
            {
                return head;
            }
        }

    ListNode* reverseList(ListNode *head)
    {
        ListNode *prev = NULL;
        ListNode *currNode = head;

        while (currNode != NULL)
        {
            ListNode *tempNode = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = tempNode;
        }
        return prev;
    }

    ListNode* validate(ListNode *head, int k)
    {
        ListNode *curr = head;
        int currLength = 1;

        while (curr->next != NULL && currLength < k)
        {
            currLength++;
            curr = curr->next;
        }
        if (currLength == k)
            return curr;
        return NULL;
    }
};