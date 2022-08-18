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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*>st;
        vector<int>ans;
        if(root==NULL)
            return ans;
        
        st.push(root);
     while(!st.empty() )
     {
           TreeNode *currNode=st.top();
          st.pop();
         ans.push_back(currNode->val);
          if(currNode->right!=NULL)
         st.push(currNode->right);
         if(currNode->left!=NULL)
         st.push(currNode->left);
        
         
         
     }
        
       return ans;
        
    }
    
    
};