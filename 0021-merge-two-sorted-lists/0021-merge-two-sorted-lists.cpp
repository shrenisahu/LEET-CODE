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
        ListNode* mergeTwoLists(ListNode *p, ListNode *q)
        {

            ListNode *head = new ListNode(-1);
            ListNode *ptr = head;

            while (p != NULL && q != NULL)
            {
                if (p->val < q->val)
                {
                    ListNode *newNode = new ListNode(p->val);
                    ptr->next = newNode;
                    ptr = ptr->next;
                    p = p->next;
                }
                else
                {
                    ListNode *newNode = new ListNode(q->val);
                    ptr->next = newNode;
                    ptr = ptr->next;
                    q = q->next;
                }
            }

            while (p != NULL)
            {
                ListNode *newNode = new ListNode(p->val);
                ptr->next = newNode;
                ptr = ptr->next;
                p = p->next;
            }
            while (q != NULL)
            {
                ListNode *newNode = new ListNode(q->val);
                ptr->next = newNode;
                ptr = ptr->next;
                q = q->next;
            }

            return head->next;
        }
};