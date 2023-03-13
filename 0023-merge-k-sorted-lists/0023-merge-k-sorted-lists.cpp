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
typedef pair<int, ListNode*> pi;
class Compare
{
    public:
        bool operator()(ListNode *r, ListNode *l)
        {

            return r->val > l->val;
        }
};

class Solution
{

    public:

        ListNode* mergeKLists(vector<ListNode*> &lists)
        {

            priority_queue<pi, vector < pi>, greater < pi>> que;

            for (auto eachList: lists)
            {
                if (eachList != NULL)
                {
                    que.push({ eachList->val,
                        eachList->next });
                }
            }
            
            ListNode* head=new ListNode(-1);
            ListNode *ptr=head;
            
            while(!que.empty())
            {
                auto currPair=que.top();
                que.pop();
                int elem=currPair.first;
                ListNode *currNode=new ListNode(elem);
                ptr->next=currNode;
                ptr=ptr->next;
                ListNode *List1=currPair.second;
                if(List1!=NULL)
                {
                    que.push({List1->val,List1->next});
                }
                
            }
            // return NULL;
            return head->next;
        }
};