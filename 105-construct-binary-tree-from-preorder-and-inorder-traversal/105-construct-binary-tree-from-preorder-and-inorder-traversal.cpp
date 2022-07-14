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
        
        int end=preorder.size()-1;
        int preIndex=0;
        unordered_map<int,int>mpp;
        
        for(int i=0;i<preorder.size();i++)
        {
            mpp[inorder[i]]=i;
        }
        
       
        
        return Construct(preorder,inorder,preIndex,0,end,mpp);
        
        
    }
    
    TreeNode* Construct(vector<int>& preorder, vector<int>& inorder,int &preIndex,int inStart,int inEnd,  unordered_map<int,int>&mpp)
    {
        if(preIndex>=preorder.size() || inStart>inEnd)
        {
            return NULL;
        }
            
        int currValue=preorder[preIndex];
        TreeNode * currNode=new TreeNode (currValue);
        // currNode=currValue;
        
        preIndex++;
int j=mpp[currValue];
        
        currNode->left=Construct(preorder,inorder,preIndex,inStart,j-1,mpp);
     currNode->right  =Construct(preorder,inorder,preIndex,j+1,inEnd ,mpp);
        return currNode;
    }
};