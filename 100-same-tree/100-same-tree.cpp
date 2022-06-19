/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        queue<pair<TreeNode*,TreeNode*>>que;
        que.push({p,q});
        
        while(!que.empty())
        {
           
                
                TreeNode*currNode1=que.front().first;
                TreeNode*currNode2=que.front().second;
                
                que.pop();
                if(currNode1==NULL && currNode2==NULL)
                    continue;
                if(currNode1==NULL || currNode2==NULL || currNode1->val !=currNode2->val)
                    return false;
                
                que.push({currNode1->left,currNode2->left});
                que.push({currNode1->right,currNode2->right});
                
            
            
            
        }
        return  true;;
    }
};