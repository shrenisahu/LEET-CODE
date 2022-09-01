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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode * dummyNode= new ListNode(-1);
        dummyNode->next=head;
        
        ListNode *prev=dummyNode;
        ListNode * currNode=head;
        
        while(currNode !=NULL)
        {
            if(currNode->val == val)
            {
                // ListNode *tempNode=currNode->next;
                prev->next=currNode->next;
                // currNode->next=NULL;
                currNode=currNode->next;
                
            }
            else 
            {
                prev=currNode;
                currNode=currNode->next;
            }
        }
        return dummyNode->next;
    }
};
