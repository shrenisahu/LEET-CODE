/**
 *Definition for singly-linked list.
 *struct ListNode {
 *int val;
 *ListNode * next;
 *ListNode() : val(0), next(nullptr) {}
 *ListNode(int x) : val(x), next(nullptr) {}
 *ListNode(int x, ListNode *next) : val(x), next(next) {}
 *};
 */
class Solution
{
    public:
        ListNode* reverseKGroup(ListNode *head, int k)
        {

            if (head == NULL)
                return head;

            bool flag = kMultiplesPossible(head, k);
            if (flag)
            {
                ListNode *temp = head;

                int i = 1;

                while (temp->next!=NULL && i < k)
                {
                    temp = temp->next;
                    i++;
                }
                ListNode *nextNode = temp->next;
                temp->next = NULL;
                ListNode *reverseHead = reverse(head, k);

                head->next = reverseKGroup(nextNode, k);
                return reverseHead;
            }
            else
                return head;
        }

    ListNode* reverse(ListNode* &head, int k)
    {
        if (head == NULL)
            return head;
        ListNode *prev = NULL;
        ListNode *curr = head;

        while (curr != NULL)
        {
            ListNode *temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }

//     bool kMultiplesPossible(ListNode *head, int k)
//     {
//         ListNode *curr = head;
//         int currLength = 1;

//         while (curr->next != NULL && currLength < k)
//         {
//             currLength++;
//             curr = curr->next;
//         }
//         if (currLength == k)
//             return true;
//         return false;
//     }
   	    bool kMultiplesPossible(ListNode *head, int k)
   	    {
   	        ListNode *temp = head;
   	        for (int i = 1; i < k && temp != NULL; i++)
   	        {
   	            temp = temp->next;
   	        }

   	        if (temp == NULL)
   	            return false;

   	        return true;
   	    }
};