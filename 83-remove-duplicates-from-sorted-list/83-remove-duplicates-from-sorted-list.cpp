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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *currNode=head;
        
        if(head==NULL)
            return NULL;
        if(head->next==NULL)
            return head;
        
        while(currNode !=NULL && currNode->next!=NULL)
        {
            if(currNode->val == currNode ->next->val)
            {
                currNode->next=currNode ->next->next;
            }
            else
            {
                currNode=currNode->next;
            }
        }
        
        return head;
        
        
    }
};