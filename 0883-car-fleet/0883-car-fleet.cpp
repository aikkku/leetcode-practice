class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> cars;
        for(int i = 0; i < position.size(); i++) {
            cars[position[i]] = speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());

        int ans = 1;
        double prev = (double)(target - position[0]) / cars[position[0]];
        for(int i = 1; i < position.size(); i++) {
            double cur = (double)(target - position[i]) / cars[position[i]];
            if(cur > prev) {
                prev = cur;
                ans++;
            }
        }

        return ans;
    }
};
