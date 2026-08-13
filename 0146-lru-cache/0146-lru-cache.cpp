class LRUCache {
public:
    class node {
    public:
        int key, val;
        node* next;
        node* prev;

        node(int k, int v) {
            key = k;
            val = v;
            next = prev = nullptr;
        }
    };

    int cap;
    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);
    unordered_map<int, node*> m;

    void addNode(node* newNode) {
        node* oldNext = head->next;
        head->next = newNode;
        newNode->prev = head;
        newNode->next = oldNext;
        oldNext->prev = newNode;
    }

    void delNode(node* delNode) {
        node* delPrev = delNode->prev;
        node* delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (m.find(key) == m.end()) {
            return -1;
        }

        node* resNode = m[key];
        int res = resNode->val;

        // Move to front (Most Recently Used)
        m.erase(key);
        delNode(resNode);
        addNode(resNode);
        m[key] = head->next;

        return res;
    }

    void put(int key, int value) {
        // If key exists, delete existing node position
        if (m.find(key) != m.end()) {
            node* existingNode = m[key];
            m.erase(key);
            delNode(existingNode);
            delete existingNode; // Clean up old allocation
        }

        // If capacity reached, remove Least Recently Used (node before tail)
        if (m.size() == cap) {
            node* lruNode = tail->prev;
            m.erase(lruNode->key);
            delNode(lruNode);
            delete lruNode; // Clean up memory
        }

        // Insert new node at head
        node* newNode = new node(key, value);
        addNode(newNode);
        m[key] = newNode;
    }
};