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
    ListNode* middleNode(ListNode* head) {
        
        ListNode *slowPtr=head;
        ListNode *fastPtr=head;
        
        while(fastPtr->next!= NULL && fastPtr->next->next!=NULL)
        {
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
        }
        if(fastPtr->next!=NULL)
            return slowPtr->next;
        
        return slowPtr;
        
        
    }
};