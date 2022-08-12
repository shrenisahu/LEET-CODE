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
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {

            ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode *prev = NULL;
            ListNode *curr = dummyNode;

            for (int i = 0; i < left; i++)
            {
                prev = curr;
                curr = curr->next;
            }

            prev->next = reverseList(curr, right - left + 1);
            return dummyNode->next;
        }

    ListNode* reverseList(ListNode *head, int noOfNodesToReverse) {
        
        ListNode* prev=NULL;
        ListNode* currNode=head;
        
        for(int i=0;i<noOfNodesToReverse;i++)
        {
            ListNode* temp=currNode->next;
            currNode->next=prev;
            prev=currNode;
            currNode=temp;
        }
        
        head->next=currNode;
        return prev;
    }
};