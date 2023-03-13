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
        ListNode* mergeKLists(vector<ListNode*> &lists)
        {

            priority_queue<int, vector < int>, greater < int>> que;
            for (ListNode *eachList: lists)
            {

                while (eachList != NULL)
                {
                    que.push(eachList->val);

                    eachList = eachList->next;
                }
            }

        if(que.size()==0)
            return NULL;
            ListNode *ptr = new ListNode(que.top());
            ListNode *head=ptr;
            que.pop();
            while (!que.empty())
            {
                int elem = que.top();
                que.pop();
                ListNode *currPtr = new ListNode(elem);
                ptr->next = currPtr;
                ptr = ptr->next;
            }

            return head;
        }
};
//  tu ja sakta hai	//