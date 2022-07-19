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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode * dummyNode= new ListNode(-1);
        ListNode *p1=list1;
        ListNode *p2=list2;
        ListNode *result=dummyNode;
        
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val < p2->val)
            {
                ListNode *newNode=new  ListNode(p1->val);
                result->next=newNode;
                p1=p1->next;
                result=result->next;
            }
            else 
            {
                 ListNode *newNode=new  ListNode(p2->val);
                 result->next=newNode;
                  p2=p2->next;
                result=result->next;
            }
        }
        
        
        if(p1!=NULL)
            
        {
            result->next=p1;
         
            
        }
        
        if(p2!=NULL)
        {
            result->next=p2;
        }
        return dummyNode->next;
    }
};