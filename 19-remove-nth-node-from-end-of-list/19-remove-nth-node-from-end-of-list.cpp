/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
       
         ListNode *dummy=new ListNode(-1);
        dummy->next=head;
         ListNode *fastPtr=dummy;
         ListNode *slowPtr=dummy;
        
        for(int i=1;i<=n;i++)
        {
            fastPtr=fastPtr->next;
        }
            
            
        while(fastPtr->next!=NULL )
        {
            fastPtr=fastPtr->next;
            slowPtr=slowPtr->next;
        }
        
        slowPtr->next=slowPtr->next->next;
        return dummy->next;
        
    }
};