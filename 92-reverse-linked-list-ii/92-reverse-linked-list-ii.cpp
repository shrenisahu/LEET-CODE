/**
 *Definition for singly-linked list.
 *struct ListNode {
 *  int val;
 *  ListNode * next;
 *  ListNode() : val(0), next(nullptr) {}
 *  ListNode(int x) : val(x), next(nullptr) {}
 *  ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseBetween(ListNode *head, int left, int right)
        {
            ListNode *dummyNode = new ListNode(-1);
            dummyNode->next = head;
            ListNode *prev = dummyNode;
            ListNode *currNode = head;
            int pos=1;
            if(head->next==NULL)
                return head;

            while (pos < left)
            {
                prev = currNode;
                currNode = currNode->next;
                pos++;
            }
            ListNode *joint1 = prev;

            while (pos < right)
            {
                prev = currNode;
                currNode = currNode->next;
                pos++;
            }
            ListNode *joint2 = currNode->next;
            currNode->next = NULL;
            ListNode *fix1 = reverse(joint1->next,joint2);
            joint1->next = fix1;
            
            
            return dummyNode->next;
        }
    ListNode* reverse(ListNode *head, ListNode *tail)
    {

        ListNode *prev = NULL;
        ListNode *currNode = head;
        ListNode *temp = currNode;
        while (currNode != NULL)
        {
            ListNode *tempNode = currNode->next;
            currNode->next = prev;
            prev = currNode;
            currNode = tempNode;
        }
        temp->next = tail;
        return prev;
    }
};