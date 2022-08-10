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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        
        int start=0;
        int end=nums.size()-1;
        return buildTree(start,end,nums);
        
        
    }
    
    TreeNode *buildTree(int start,int end,vector<int>&nums)
    {
        if(start>end)
            return NULL;
        
        int mid=start+(end-start)/2;
        TreeNode* newNode =new TreeNode(nums[mid]);
        newNode->left=buildTree(start,mid-1,nums);
        newNode->right=buildTree(mid+1,end,nums);
        
        return newNode;
    }
};