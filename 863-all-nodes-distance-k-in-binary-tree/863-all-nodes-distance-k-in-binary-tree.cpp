/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
          vector<int>ans;
        unordered_set<TreeNode*>visited;
        
        unordered_map<TreeNode*,TreeNode*>mpp;
        queue<pair<TreeNode*,TreeNode*>>que;
         queue<pair<TreeNode*,int>>que2;
        
        que.push({root,NULL});
        
        while(!que.empty())
        {
           
                auto currPair=que.front();
                TreeNode*currNode=currPair.first;
                TreeNode*currParent=currPair.second;
                que.pop();
                mpp[currNode]=currParent;
                
                if(currNode->left)
                que.push({currNode->left,currNode});
                
                if(currNode->right)
                que.push({currNode->right,currNode});    
                
            // }
        }
        
       
        
        que2.push({target,k});
        while(!que2.empty())
        {
           
            
           auto  currPair=que2.front();
                que2.pop();
                
                TreeNode*currNode=currPair.first;
                  if(visited.find(currNode)!=visited.end() )
                  {
                      continue;
                  }
                
                visited.insert(currNode);
                int distance=currPair.second;
                
                if(distance==0 )
                {
                    
                        ans.push_back(currNode->val);
                        continue;
                   
                }
                
                    if(currNode->left)
                        que2.push({currNode->left,distance-1});
                    
                     if(currNode->right)
                        que2.push({currNode->right,distance-1});
                    
                    if(mpp[currNode])
                     que2.push({mpp[currNode],distance-1});
                    
                    
                    
                
            
            
            
        }
        return ans;
        
        
        
        
    }
};