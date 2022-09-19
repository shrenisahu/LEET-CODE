/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *int val;
 *TreeNode * left;
 *TreeNode * right;
 *TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 *};
 */
class Codec
{
    public:

       	// Encodes a tree to a single string.
        string serialize(TreeNode *root)
        {
            string nodesIndex = "";

            if (root == NULL)
                return nodesIndex;
            queue<TreeNode*> que;

            que.push(root);
            while (!que.empty())
            {
                TreeNode *currNode = que.front();
                que.pop();
                if (currNode == NULL)
                {
                    nodesIndex += "#,";
                }
                else
                    nodesIndex += to_string(currNode->val) + ',';

                if (currNode != NULL)
                {
                    que.push(currNode->left);
                    que.push(currNode->right);
                }
            }
            cout << nodesIndex << endl;
            return nodesIndex;
        }

   	// Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {
        if (data.size() == 0)
            return NULL;
        stringstream obj; //    stringstream obj(data);
        obj << data;
        string str;
        getline(obj, str, ',');

        if (str == "#")
            return NULL;

        queue<TreeNode*> que;
        TreeNode *root = new TreeNode(stoi(str));
        que.push(root);
        while (!que.empty())
        {

            TreeNode *currNode = que.front();
            que.pop();
            string left;
            getline(obj, left, ',');
            if (left == "#")
                currNode->left == NULL;
            else
            {
                TreeNode *leftNode = new TreeNode(stoi(left));
                currNode->left = leftNode;
                que.push(leftNode);
            }

            string right;
            getline(obj, right, ',');
            if (right == "#")
                currNode->right == NULL;
            else
            {
                TreeNode *rightNode = new TreeNode(stoi(right));
                currNode->right = rightNode;
                que.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));