class LFUCache {
    struct Node {
        int val;
        Node* prev;
        Node* next;

        Node(int val) : val(val), prev(nullptr), next(nullptr) {}
        Node(int val, Node* prev, Node* next) : val(val), prev(prev), next(next) {}
    };

    struct LinkedList {
        Node* left;
        Node* right;
        unordered_map<int, Node*> mp;

        LinkedList() {
            left = new Node(0);
            right = new Node(0);
            left->next = right;
            right->prev = left;
        }

        ~LinkedList() {
            while(left->next != right) {
                Node* temp = left->next;
                left->next = temp->next;
                delete temp;
            }

            delete left;
            delete right;
        }

        int length() {
            return mp.size();
        }

        void pushRight(int val) {
            Node* temp = new Node(val, right->prev, right);
            mp[val] = temp;
            right->prev->next = temp;
            right->prev = temp;
        }

        void pop(int val) {
            if(mp.find(val) != mp.end()) {
                Node* node = mp[val];
                Node* prev = node->prev;
                Node* next = node->next;

                prev->next = next;
                next->prev = prev;
                mp.erase(val);
                delete node;
            }
        }

        int popLeft() {
            int res = left->next->val;
            pop(res);
            return res;
        }

        void update(int val) {
            pop(val);
            pushRight(val);
        }
    };

    int capacity;
    int lfuCount;
    unordered_map<int, int> valMap;
    unordered_map<int, int> countMap;
    unordered_map<int, LinkedList*> listMap;

    void counter(int key) {
        int count = countMap[key];
        countMap[key] = count + 1;

        listMap[count]->pop(key);

        if(!listMap.count(count + 1)) {
            listMap[count + 1] = new LinkedList();
        }
        listMap[count + 1]->pushRight(key);

        if(count == lfuCount && listMap[count]->length() == 0) {
            lfuCount++;
        }
    }

public:
    LFUCache(int capacity) : capacity(capacity), lfuCount(0) {
        listMap[0] = new LinkedList();
    }

    ~LFUCache() {
        for (auto& pair : listMap) {
            delete pair.second;
        }
    }
    
    int get(int key) {
        if (valMap.find(key) == valMap.end()) {
            return -1;
        }
        counter(key);
        return valMap[key];
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;

        if(valMap.find(key) == valMap.end() && valMap.size() == capacity) {
            int toRemove = listMap[lfuCount]->popLeft();
            valMap.erase(toRemove);
            countMap.erase(toRemove);
        }

        valMap[key] = value;
        if(countMap.find(key) == countMap.end()) {
            countMap[key] = 0;
            listMap[0]->pushRight(key);
            lfuCount = 0;
        }
        counter(key);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */