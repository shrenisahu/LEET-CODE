/**
 *Definition for singly-linked list.
 *struct ListNode {
 *   int val;
 *   ListNode * next;
 *   ListNode() : val(0), next(nullptr) {}
 *   ListNode(int x) : val(x), next(nullptr) {}
 *   ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* oddEvenList(ListNode *head)
        {
            if (head == NULL || head->next == NULL || head->next->next == NULL)
                return head;
            ListNode *oddHead = head;
            ListNode *evenHead = head->next;
            ListNode *oddPtr = oddHead;
            ListNode *evenPtr = evenHead;

            while (evenPtr != NULL && evenPtr->next != NULL)
            {

                oddPtr->next = oddPtr->next->next;
                evenPtr->next= evenPtr->next->next;
                oddPtr = oddPtr->next;
                evenPtr = evenPtr->next;
            }
            oddPtr->next = evenHead;
            return head;
        }
};