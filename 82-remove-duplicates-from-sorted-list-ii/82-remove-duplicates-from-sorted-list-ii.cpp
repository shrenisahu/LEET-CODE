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
        ListNode* deleteDuplicates(ListNode *head)
        {

            ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode *currNode = head;
            ListNode *prev = dummyNode;
            
            if(head==NULL)
                return NULL;
           
            while ( currNode!= NULL && currNode->next!=NULL )
            {
                if (currNode->val == currNode->next->val)
                {
                    while ( currNode->next!=NULL && currNode->val == currNode->next->val )
                    {
                        
                        currNode = currNode->next;
                    }
                  
                    prev->next = currNode->next;
                    currNode=currNode->next;
                    
                }
                else
                {
                    prev = currNode;

                    currNode = currNode->next;
                }
            }
            
            return dummyNode->next;
        }
};