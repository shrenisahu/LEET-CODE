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
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        return Build(0,n-1,0,n-1,preorder,inorder ,mpp);
    }
    
    
    TreeNode * Build(int preStart,int preEnd,int inStart,int inEnd,vector<int>& preorder, vector<int>& inorder , unordered_map<int,int>&mpp)
    {
        if(preStart >preEnd || inStart >inEnd)
            return NULL;
        
        
        
        int currElem=preorder[preStart];
        int pos=mpp[currElem];
        int elementsinLeftSizeInorder=pos-inStart;
        
        TreeNode *currNode=new TreeNode(currElem);
        
        currNode->left=Build(preStart+1,preStart+elementsinLeftSizeInorder,inStart,pos-1,preorder,inorder ,mpp);
        currNode->right=Build(preStart+elementsinLeftSizeInorder+1,preEnd,pos+1,inEnd,preorder,inorder ,mpp);
        
        return currNode;
        
    }
};