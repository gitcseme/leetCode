class LRUCache {
private:
    list<int> lru;
    unordered_map<int, int> kv_store;
    unordered_map<int, list<int>::iterator> key_locator;
    int CAPACITY;

    void updateLru(int key) {
        if (kv_store.count(key)) {
            lru.erase(key_locator[key]);
        }
        lru.push_front(key);
        key_locator[key] = lru.begin();
    }

    // cache eviction policy
    void evict() {
        int key = lru.back();
        lru.pop_back();
        kv_store.erase(key);
        key_locator.erase(key);
    }

public:
    LRUCache(int capacity) {
        CAPACITY = capacity;
    }
    
    int get(int key) {
        if (kv_store.count(key) == 0) {
            return -1;
        }

        updateLru(key);
        return kv_store[key];
    }
    
    void put(int key, int value) {
        // key not found -> new insert. check capacity
        if (kv_store.count(key) == 0 && lru.size() == CAPACITY) {
            evict();
        }

        updateLru(key);
        kv_store[key] = value;
    }
};

