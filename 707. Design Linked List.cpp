class MyLinkedList {
public:
    class Node {
    public:    
        int value;
        Node* next;
        Node(int _value, Node* _next) {
            value = _value;
            next = _next;
        }
    };

    int length;
    Node* dummyHead = nullptr;

    MyLinkedList() {
        length = 0;
        dummyHead = new Node(0, nullptr);
    }

    ~MyLinkedList() {
        auto curr = dummyHead;
        while (length--) {
            auto nodeToRemove = curr;
            curr = curr->next;
            cout << nodeToRemove->value << "\n";
            delete(nodeToRemove);
        }
    }
    
    int get(int index) {
        if (index < 0 || index >= length) return -1;

        Node* curr = dummyHead->next;
        while (index--) {
            curr = curr->next;
        }

        return curr->value;
    }
    
    void addAtHead(int val) {
        addAtIndex(0, val);
    }
    
    void addAtTail(int val) {
        addAtIndex(length, val);
    }
    
    void addAtIndex(int index, int val) {
        if (index > length) return;
        
        Node* curr = dummyHead;
        while (index--) {
            curr = curr->next;
        }
        
        Node* newNode = new Node(val, nullptr);
        newNode->next = curr->next;
        curr->next = newNode;
        ++length;
    }
    
    void deleteAtIndex(int index) {
        if (index < 0 || index >= length) return;
        
        Node* curr = dummyHead;
        while (index--) {
            curr = curr->next;
        }

        Node* nodeToDelete = curr->next;
        curr->next = curr->next->next;
        delete(nodeToDelete);
        --length;
    }
};

