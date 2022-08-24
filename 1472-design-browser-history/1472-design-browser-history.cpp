class Node
{
    public:
        string url;
    Node * prev;
    Node * next;
    Node()
    {
        url = "";
        prev = NULL;
        next = NULL;
    }
    Node(string url)
    {
        this->url = url;
        prev = NULL;
        next = NULL;
    }
};

class BrowserHistory
{
    public:

        Node *head = new Node();
    Node *iterator = new Node();

    BrowserHistory(string homepage)
    {
        Node *newNode = new Node(homepage);
        head->next = newNode;
        iterator = newNode;
    }

    void visit(string url)
    {

        Node *newNode = new Node(url);
        iterator->next = newNode;
        newNode->prev = iterator;
        iterator = newNode;
        return;
    }

    string back(int steps)
    {

        while (iterator->prev != NULL && steps > 0)
        {
            iterator = iterator->prev;
            steps -= 1;
        }
        return iterator->url;
    }

    string forward(int steps)
    {
        while (iterator->next != NULL && steps > 0)
        {
            iterator = iterator->next;
            steps -= 1;
        }
        return iterator->url;
    }
};

/**
 *Your BrowserHistory object will be instantiated and called as such:
 *BrowserHistory* obj = new BrowserHistory(homepage);
 *obj->visit(url);
 *string param_2 = obj->back(steps);
 *string param_3 = obj->forward(steps);
 */