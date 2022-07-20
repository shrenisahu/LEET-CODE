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
    bool isPalindrome(ListNode* head) {
        ListNode *fastPtr=head;
        ListNode *slowPtr=head;
        
        while(fastPtr->next!=NULL && fastPtr->next->next!=NULL)
        {
            fastPtr=fastPtr->next->next;
            slowPtr=slowPtr->next;
            
        }
         ListNode *tempList=slowPtr->next;
        slowPtr->next=NULL;
        ListNode *newList=reverseList(tempList);
        
        return compareList(head,newList);
        
    }
    bool compareList(ListNode *list1 ,ListNode *list2)
    {
       while(list1!=NULL && list2!=NULL)
       {
            if(list1->val !=list2->val)
            return false;
           
           list1=list1->next;
           list2=list2->next;
       }
        return true;
    }
    ListNode *reverseList(ListNode *head)
    {
        ListNode *dummyNode=new ListNode(-1);
        dummyNode->next=head;
        ListNode *prev=NULL;
        ListNode *currNode=head;
        
        while(currNode!=NULL)
        {
            ListNode *tempNode=currNode->next;
            currNode->next=prev;
            prev=currNode;
            currNode=tempNode;
        }
        
        return prev;
    }
};