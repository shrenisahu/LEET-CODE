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
        
        ListNode *p1=reverse(l1);
        ListNode *p2=reverse(l2);
        
      ListNode *tempAns=  addNum(p1,p2);
      ListNode *finalAns=reverse(tempAns);
        
        return finalAns;
        
        
    }
    ListNode *addNum(ListNode *p1,ListNode *p2)
    {
        int carry=0;
        ListNode *dummyNode=new ListNode(-1);
        ListNode *currNode=dummyNode;
        
        while(p1!=NULL && p2!=NULL)
        {
            int tempSum=p1->val + p2->val + carry;
            carry=tempSum/10;
            int newValue=tempSum%10;
            ListNode *newNode=new ListNode(newValue);
            
            currNode->next=newNode;
            currNode=currNode->next;
            p1=p1->next;
            p2=p2->next;
            
            
            
        }
        
        while(p1!=NULL)
        {
            int newValue=p1->val+carry;
            carry=newValue/10;
            ListNode *newNode=new ListNode(newValue%10);
            p1=p1->next;
            currNode->next=newNode;
            currNode=currNode->next;
            
        }
          while(p2!=NULL)
        {
            int newValue=p2->val+carry;
            carry=newValue/10;
            ListNode *newNode=new ListNode(newValue%10);
            p2=p2->next;
            currNode->next=newNode;
            currNode=currNode->next;
            
        }
        
        if(carry >0)
            {
                ListNode *newNode=new ListNode(carry);
                currNode->next=newNode;
                
            }
            
            return dummyNode->next;
        
    }
    
    ListNode *reverse(ListNode * head)
    {
        ListNode * dummyNode= new ListNode(-1);
        ListNode *prev=NULL;
        ListNode * currNode=head;
        
        
        while(currNode !=NULL)
        {
            ListNode *tempNode=currNode->next;
            currNode->next=prev;
            prev=currNode;
            currNode=tempNode;
            
        }
        
        return prev;
    }
    
    
   
};