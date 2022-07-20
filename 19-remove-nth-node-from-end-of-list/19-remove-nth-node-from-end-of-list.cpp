/**
 *Definition for singly-linked list.
 *struct ListNode {
 *    int val;
 *    ListNode * next;
 *    ListNode() : val(0), next(nullptr) {}
 *    ListNode(int x) : val(x), next(nullptr) {}
 *    ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* removeNthFromEnd(ListNode *head, int n)
        {
            if(head==NULL || head->next==NULL)
                return NULL;
            
            ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode *ptr1 = dummyNode;
            ListNode *ptr2 = dummyNode;
            for (int i = 1; i <= n; i++)
            {
                ptr1 = ptr1->next;
            }
            while (ptr1->next != NULL)
            {
                ptr2 = ptr2->next;
                ptr1 = ptr1->next;
            }
            ptr2->next = ptr2->next->next;

            return dummyNode->next;
        }
};