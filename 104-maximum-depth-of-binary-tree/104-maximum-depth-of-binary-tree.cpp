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
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=0;
        queue<TreeNode*>que;
        que.push(root);
        
        while(!que.empty())
        {
            int size=que.size();
            
            for(int i=0;i<size;++i)
            {
                TreeNode *currNode=que.front();
                que.pop();
                if(currNode->left)
                    que.push(currNode->left);
                
                if(currNode->right)
                    que.push(currNode->right);
                
            }
            ans++;
        }
        
        return ans;
        
    }
    
    
    
};