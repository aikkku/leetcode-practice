class MyHashMap {
public:
    MyHashMap() {
        this->capacity = 1000000;
        this->v = vector<pair<int,int>>(capacity, EMPTY);
        this->count = 0;
    }
    
    void put(int k, int value) {
        int key = hashing(k);
        while (v[key] != EMPTY) {
            if (v[key].first == k) {
                v[key].second = value;
                return;
            }
            key = (key + 1) % capacity;
        }
        v[key] = {k, value};
        count++;
        if (count >= capacity / 2) resize();
    }
    
    int get(int k) {
        int key = hashing(k);
        while (v[key] != EMPTY) {
            if (v[key].first == k) return v[key].second;
            key = (key + 1) % capacity;
        }
        return -1;
    }
    
    void remove(int k) {
        int key = hashing(k);
        while (v[key] != EMPTY) {
            if (v[key].first == k) {
                v[key] = EMPTY;
                count--;
                return;
            }
            key = (key + 1) % capacity;
        }
        return;
    }

private:
    const pair<int, int> EMPTY = {-1, -1};
    int capacity;
    int count;
    vector<pair<int, int>> v;

    int hashing(int key) {
        return key % capacity;
    }

    void resize() {
        int oldCapacity = capacity;
        vector<pair<int, int>> oldV = v;
        capacity *= 2;
        v = vector<pair<int, int>>(capacity, EMPTY);
        count = 0;
        for (int i = 0; i < oldCapacity; ++i) {
            if (oldV[i] != EMPTY) {
                put(oldV[i].first, oldV[i].second);
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */