class MyHashMap {
private:
    class Node {
    public:
        int key, value;
        Node* next;
        Node(int _key, int _value, Node* _next) {
            key = _key;
            value = _value;
            next = _next;
        }
    };

    const static int CAPACITY = 1997;
    const static int BASE = 997;
    const static int OFFSET = 1797;
    vector<Node*> _store;

    int calculateHash(int key) {
        return ((key * BASE) + OFFSET) % CAPACITY;
    }

public:
    MyHashMap() {
        _store.resize(CAPACITY);
    }
    
    void put(int key, int value) {
        remove(key);
        int H = calculateHash(key);
        auto node = new Node(key, value, _store[H]);
        _store[H] = node;
    }
    
    int get(int key) {
        int H = calculateHash(key);
        auto node = _store[H];

        while (node) {
            if (node -> key == key) {
                return node -> value;
            }
            node = node -> next;
        }
        return -1;
    }
    
    void remove(int key) {
        int H = calculateHash(key);
        auto node = _store[H];

        if (node == nullptr) return; // No key exits

        if (node -> key == key)  { // head is the node
            _store[H] = node -> next;
            delete(node);
            return;
        }   

        // find the node 
        while (node && node -> next) {
            if (node -> next -> key == key) {
                auto toBeDeleted = node -> next;
                node -> next = toBeDeleted -> next;
                delete(toBeDeleted);
            }
            node = node -> next;
        }
    }
};
