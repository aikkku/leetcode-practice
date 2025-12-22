class Compare {
public:
	bool operator()(pair<int, int> a, pair<int, int> b) {
		if(a.second < b.second) {
			return true;
		}
		return false;
	}
};


class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        int first = INT_MIN, second = INT_MIN;
        for(int i : nums) {
            mp[i]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, Compare> pq;
        for(auto it = mp.begin(); it != mp.end(); it++) {
            pq.push({it->first, it->second});
        }

        vector<int> ans;
        while(!pq.empty() and k--) {
            ans.push_back(pq.top().first);
            pq.pop();
        }

        return ans;
    }
};