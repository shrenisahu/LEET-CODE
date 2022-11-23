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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        int carry=0;
        ListNode *p1=l1;
        ListNode *p2=l2;
        
        ListNode * dummyNode= new ListNode(-1);
        ListNode *currNode=dummyNode;
        while(p1!=NULL && p2!=NULL)
        {
            int newData=p1->val + p2->val + carry;
             carry=newData/10;
            int actualValue=newData % 10;
            
            ListNode* newNode =new ListNode(actualValue);
            currNode->next=newNode;
            currNode=currNode->next;
            p1=p1->next;
            p2=p2->next;
            
        }
        
        while(p1!=NULL)
        {
            int tempValue=p1->val+carry;
            carry=tempValue/10;
            int newValue=tempValue%10;
            ListNode * newNode=new ListNode(newValue);
            p1=p1->next;
            currNode->next=newNode;
            currNode=currNode->next;
        }
        
        while(p2!=NULL)
        {
             int tempValue=p2->val+carry;
            carry=tempValue/10;
            int newValue=tempValue%10;
            ListNode * newNode=new ListNode(newValue);
            p2=p2->next;
            currNode->next=newNode;
            currNode=currNode->next;
        }
        
        if(carry!=0)
        {
            ListNode *tempNode=new ListNode(carry);
            currNode->next=tempNode;
            
        }
        
        return dummyNode->next;
        
        
        
    }
};