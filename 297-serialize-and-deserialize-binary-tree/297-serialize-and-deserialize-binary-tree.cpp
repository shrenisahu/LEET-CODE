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

            string data = "";
            Preoder(root, data);
            cout << data;

            return data;
        }

    void Preoder(TreeNode *root, string &data)
    {

        if (root == NULL)
        {
            data += "#,";
            return;
        }
        data += to_string(root->val) + ',';
        Preoder(root->left, data);
        Preoder(root->right, data);
        return;
    }
   	// Decodes your encoded data to tree.
    TreeNode* deserialize(string data)
    {

        if (data.size() == 0)
            return NULL;
        int index = 0;
        return constructTree(data, index);
    }

    int getValue(string data, int &i)
    {
        string res = "";
        while (data[i] != ',')
        {
            res += data[i];
            i++;
        }
        i++;
        return stoi(res);
    }

    TreeNode* constructTree(string data, int &index)
    {
        if (data[index] == '#')
        {
            index+=2;
            return NULL;
        }

        int currVal = getValue(data, index);

        TreeNode *root = new TreeNode(currVal);
        root->left = constructTree(data, index);
        root->right = constructTree(data, index);

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));