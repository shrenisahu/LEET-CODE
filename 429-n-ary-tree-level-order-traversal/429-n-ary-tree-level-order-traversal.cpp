/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution
{
    public:
        vector<vector < int>> levelOrder(Node *root)
        {
             
            queue<Node*> que;
            que.push(root);
            vector<vector < int>> ans;
            if(root==NULL) return ans;

            while (!que.empty())
            {
                int size = que.size();
                vector<int> temp;
                for (int i = 0; i < size; i++)
                {
                    Node *currNode = que.front();
                    que.pop();
                    temp.push_back(currNode->val);
                    vector<Node*> child = currNode->children;
                    for (auto eachChild: child)
                    {
                        que.push(eachChild);
                    }
                }
                ans.push_back(temp);
            }
            return ans;
        }
};