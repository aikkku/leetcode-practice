class LRUCache {
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if(this->mp.find(key) == this->mp.end()) return -1;
        Node* cur = mp[key];
        if(cur == this->first) {
            if (this->mp.size()>1) {
                first = cur->next;
                if (first) first->prev = nullptr;
                this->last->next = cur;
                cur->prev = this->last;
                cur->next = nullptr;
                last = cur;
            }
        } else if (cur != this->last) {
            if (cur->prev) cur->prev->next = cur->next;
            if (cur->next) cur->next->prev = cur->prev;
            cur->prev = this->last;
            this->last->next = cur;
            cur->next = nullptr;
            this->last = cur;
        }

        return cur->val.second;
    }
    
    void put(int key, int value) {
        if (mp.find(key) != mp.end()) {
            Node* existing = mp[key];
            existing->val.second = value;
            if (existing != last) {
                if (existing == first) {
                    first = existing->next;
                    if (first) first->prev = nullptr;
                }
                if (existing->prev) existing->prev->next = existing->next;
                if (existing->next) existing->next->prev = existing->prev;
                existing->prev = last;
                existing->next = nullptr;
                last->next = existing;
                last = existing;
            }
            return;
        }

        Node* cur = new Node({key, value});
        if(this->mp.empty()) {
            this->first = cur;
            this->last = cur;
        } else if(this->mp.size() < this->capacity) {
            cur->prev = this->last;
            this->last->next = cur;
            this->last = cur;
        } else {
            cur->prev = this->last;
            this->last->next = cur;
            this->last = cur;

            mp.erase(this->first->val.first);
            Node* oldFirst = this->first;
            this->first = this->first->next;
            if (this->first) this->first->prev = nullptr;
            delete oldFirst;
        }
        this->mp[key] = cur;
    }

private:
    int capacity;
    struct Node {
        pair<int, int> val;
        Node* next;
        Node* prev;
        
        Node(pair<int, int> val) {
            this->val = val;
            this->next = nullptr;
            this->prev = nullptr;
        }
    };
    Node* first;
    Node* last;
    unordered_map<int, Node*> mp;
};
