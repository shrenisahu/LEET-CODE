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
            if(head==NULL)
                return head;

            int numberOfJumpsToREachEnd = 0;
            int LoopVar = 0;

            ListNode *currNode = head;
            
            while (currNode->next)
            {
                numberOfJumpsToREachEnd++;
                currNode = currNode->next;
                
            }
            if (numberOfJumpsToREachEnd % 2 == 0)
                LoopVar = numberOfJumpsToREachEnd / 2;
            else
            {
                LoopVar = (numberOfJumpsToREachEnd + 1) / 2;
            }
            ListNode *start=head;
            ListNode *end=currNode;
            ListNode *temp=start;
            
            for(int i=0;i<LoopVar;i++)
            {
                end->next=temp->next;
                temp->next=temp->next->next;
                end->next->next=NULL;
                temp=temp->next;
                end=end->next;
            }
         
            return head;
        }
};