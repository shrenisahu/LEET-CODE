/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Solution
{
    unordered_map<TreeNode*, TreeNode*> mpp;
    public:
        vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
        {
            vector<int> ans;
            if (root == NULL)
                return ans;

            mpp[root] = new TreeNode(-1);
            fillMapWithParents(root);
            BFS(target,ans,k);
            return ans;
        }

    void BFS(TreeNode *root, vector<int> &ans, int k)
    {
        queue<TreeNode*> que;
        set<TreeNode*> seen;
        que.push(root);
        int currLevel = 0;
        while (!que.empty())
        {
            int size = que.size();
            for (int i = 0; i < size; i++)
            {
                TreeNode *currNode = que.front();
                que.pop();
                if (seen.find(currNode) != seen.end())
                    continue;
                seen.insert(currNode);
                if (currLevel == k)
                    ans.push_back(currNode->val);
                if (currNode->left)
                    que.push(currNode->left);
                if (currNode->right)
                    que.push(currNode->right);
                TreeNode *par = mpp[currNode];
                if (par->val != -1)
                {
                    que.push(par);
                }
            }
            currLevel++;
        }
    }

    void fillMapWithParents(TreeNode *root)
    {
        if (root == NULL)
            return;

        if (root->left)
            mpp[root->left] = root;
        if (root->right)
            mpp[root->right] = root;
        fillMapWithParents(root->left);
        fillMapWithParents(root->right);
    }
};