class Node
{
    public:
        int val;
    int key;
    Node * prev;
    Node * next;
    Node()
    {
        prev = NULL;
        next = NULL;
    }
    Node(int key, int value)
    {
        this->key = key;
        this->val = value;
    }
};
class LRUCache
{

    public:

        Node *head = new Node(-1, -1);
    Node *tail = new Node(-1, -1);

    int size = 0;
    int currSize = 0;
    unordered_map<int, Node*> mpp;

    LRUCache(int capacity)
    {
        head->next = tail;
        tail->prev = head;
        head->prev = tail;
        tail->next = head;
        size = capacity;
    }

    int get(int key)
    {

        if (mpp.find(key) != mpp.end()) // if key is present in map we will push it o MRU from LRU and return key value;
        {
            Node *currNode = mpp[key];
            deleteAtFront(currNode);
            insertAtTail(currNode);
            return currNode->val;
        }
        else // not in map return -1;
        {
            return -1;
        }
    }

    void put(int key, int value)
    {
  
        if (currSize == size) // if the list if full .
        {

           
            if (mpp.find(key) != mpp.end())  // if the element that we want to put in list is present in map then we need to delete it from its pos and insert it at MRU(insert at tail)
            {
                Node *currNode = mpp[key]; // here we are deleting it
                deleteAtFront(currNode);
              
                currSize -= 1;
                mpp.erase(key);
               
            }
            else // if size is full and element is not in map just delete the eleemnt at head
            {
                Node *curr=head->next;
                deleteAtFront(curr);
                mpp.erase(curr->key);
                 currSize -= 1;
                
            }
            Node *newNode = new Node(key, value); // after deleting we will insert at tail
            insertAtTail(newNode);
            mpp[key] = newNode;
            currSize += 1;
        }
        else
        {
            if (mpp.find(key) != mpp.end())
            {
                Node *currNode = mpp[key];
                deleteAtFront(currNode);
                currSize -= 1;
                mpp.erase(key);
            }
            Node *newNode = new Node(key, value);
            insertAtTail(newNode);
            mpp[key] = newNode;
            currSize += 1;
        }
    }

    void insertAtTail(Node *nodeToInsert)
    {
        nodeToInsert->next = tail;
        nodeToInsert->prev = tail->prev;
        nodeToInsert->prev->next = nodeToInsert;
        tail->prev = nodeToInsert;
       	//  tail=nodeToInsert; 
    }
   	// always delete form front because note at front is least recent node having higher priority
    void deleteAtFront(Node *nodeToDelete)
    {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;

        ;
        nodeToDelete->next = NULL;
        nodeToDelete->prev = NULL;
    }
};

/**
 *Your LRUCache object will be instantiated and called as such:
 *LRUCache* obj = new LRUCache(capacity);
 *int param_1 = obj->get(key);
 *obj->put(key,value);
 */