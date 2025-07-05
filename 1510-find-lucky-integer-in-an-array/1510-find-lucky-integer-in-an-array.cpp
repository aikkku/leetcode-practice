class Solution {
public:
    int findLucky(vector<int>& arr) {
        unordered_map<int, int> mp;

        for(int i = 0; i < arr.size(); i++) mp[arr[i]]++;

        int count(-1);
        for(auto it = mp.begin(); it != mp.end(); it++) {
            if(it->first == it->second and it->first > count) count=it->first;
        }

        return count;
    }
};