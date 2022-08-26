class Node
{
    public:
        int key;
    int val;
    Node * prev;
    Node * next;

  
    Node(int key, int data)
    {
        this->key = key;
        this->val = data;
    }
};

class LRUCache
{

    Node *head = new Node(-1,-1);
    Node *tail = new Node(-1,-1);
    unordered_map<int, Node*> mpp;
    
    int maxSize = 0;

    public:
        LRUCache(int capacity)
        {
            head->next = tail;
            tail->prev = head;
            head->prev = NULL;
            tail->next = NULL;
            maxSize = capacity;
        }

    int get(int key)
    {

        if (mpp.find(key) != mpp.end())
        {
            Node *curr = mpp[key];

            deleteNode(curr);
            insertAtTail(curr);
            return curr->val;
        }
        else
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
          if (mpp.find(key) != mpp.end())
            {
               Node *currNode = mpp[key];
        deleteNode(currNode);
       
        mpp.erase(key);
            }
        if (mpp.size() == maxSize)
        {

//             if (mpp.find(key) == mpp.end())
//             {
                
           
                Node *curr = head->next;
                deleteNode(curr);
                mpp.erase(curr->key);
               
            // }
        }
       
        Node *newNode = new Node(key, value);
        insertAtTail(newNode);
        mpp[key] = newNode;
        
    }

    void deleteNode(Node *curr)
    {
        curr->prev->next = curr->next;
        curr->next->prev = curr->prev;
        curr->next = NULL;
        curr->prev = NULL;
    }

    void insertAtTail(Node *curr)
    {
        curr->next = tail;
        curr->prev = tail->prev;
        curr->prev->next = curr;
        tail->prev = curr;
    }

   
  
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */