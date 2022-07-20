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
        ListNode* deleteMiddle(ListNode *head)
        {
             
            ListNode *dummyNode=new ListNode(-1);
            dummyNode->next=head;
            ListNode *slowPtr = dummyNode;
            ListNode *fastPtr = dummyNode;
            
            while(fastPtr->next!=NULL && fastPtr->next->next!=NULL)
            {
                fastPtr=fastPtr->next->next;
                slowPtr=slowPtr->next;
            }
           ListNode *temp=slowPtr->next;
            slowPtr->next=slowPtr->next->next;
            delete(temp);
            
            return dummyNode->next;
        }
};