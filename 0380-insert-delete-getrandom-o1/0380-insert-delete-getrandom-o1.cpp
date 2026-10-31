class RandomizedSet {
public:
    RandomizedSet() {}

    bool insert(int val) {
        if (mp.contains(val)) {
            return false;
        } else {
            mp[val] = v.size();
            v.push_back(val);
            return true;
        }
    }

    bool remove(int val) {
        if (mp.contains(val)) {
            int temp = v[v.size() - 1];
            v[v.size() - 1] = val;
            v[mp[val]] = temp;
            v.pop_back();
            mp[temp] = mp[val];
            mp.erase(val);
            return true;
        } else {
            return false;
        }
    }

    int getRandom() { return v[rand() % v.size()]; }

private:
    vector<int> v;
    unordered_map<int, int> mp;
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */