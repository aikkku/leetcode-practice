class TimeMap {
public:
    TimeMap() {}

    void set(string key, string value, int timestamp) {
        great_mp[key].push_back({timestamp, value});

        // struct {
        //     bool operator()(pair<int, string> l, pair<int, string> h) {
        //         return l.first > h.first;
        //     }
        // } CustomCompare;

        // sort(great_mp[key].begin(), great_mp[key].end(), CustomCompare);
    }

    string get(string key, int timestamp) {
        if (great_mp[key].empty())
            return "";

        int l = 0, r = great_mp[key].size() - 1;
        int mid, best = 0;
        while (l <= r) {
            mid = (r - l) / 2 + l;

            if (great_mp[key][mid].first == timestamp) {
                return great_mp[key][mid].second;
            } else if (great_mp[key][mid].first < timestamp) {
                best = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }

        return great_mp[key][best].first <= timestamp
                   ? great_mp[key][best].second
                   : "";
    }

private:
    unordered_map<string, vector<pair<int, string>>> great_mp;
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */