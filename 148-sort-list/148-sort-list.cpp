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
        ListNode* sortList(ListNode *head)
        {
            if(head==NULL)
                return NULL;
            if (head->next == NULL)
                return head;

            ListNode *ListTow = findMiddleNode(head);

            ListNode *node1 = head;
            ListNode *node2 = ListTow->next;;
            ListTow->next = NULL;
            ListNode *part1 = sortList(node1);
            ListNode *part2 = sortList(node2);

            ListNode *newList = mergeList(part1, part2);

            return newList;
        }

    ListNode* findMiddleNode(ListNode *head)
    {

        ListNode *fstPtr = head;
        ListNode *slowPtr = head;

        while ( fstPtr->next != NULL && fstPtr->next->next != NULL)
        {
            slowPtr = slowPtr->next;
            fstPtr = fstPtr->next->next;
        }
        return slowPtr;
    }

    ListNode* mergeList(ListNode *list1, ListNode *list2) {
        ListNode *dummyNode= new ListNode(-1);
        ListNode *head=dummyNode;
        ListNode *p1=list1;
        ListNode *p2=list2;
        
        while(p1!=NULL && p2!=NULL)
        {
            if(p1->val <p2->val)
            {
                ListNode *newNode=new ListNode(p1->val);
                head->next=newNode;
                head=head->next;
                p1=p1->next;
            }
            else
            {
                ListNode *newNode=new ListNode(p2->val);
                head->next=newNode;
                head=head->next;
                p2=p2->next;
            }
            
        }
        
        if(p1!=NULL)
        {
            head->next=p1;
            
        }
        if(p2!=NULL)
        {
            head->next=p2;
        }
        
        
        
        return dummyNode->next;
        
    }
};