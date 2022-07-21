/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        
        unordered_set<ListNode *>stt;
        ListNode *currNode=head;
        
        while(currNode!=NULL)
        {
            
            if(stt.find(currNode)!=stt.end())
                return true;
            stt.insert(currNode);
            currNode=currNode->next;
        }
        
        return false;
        
    }
};