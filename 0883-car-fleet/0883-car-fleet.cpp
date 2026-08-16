class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        unordered_map<int, int> cars;
        for(int i = 0; i < position.size(); i++) {
            cars[position[i]] = speed[i];
        }

        sort(position.begin(), position.end(), greater<int>());

        vector<double> st;
        for(int i = 0; i < position.size(); i++) {
            st.push_back((double)(target - position[i]) / cars[position[i]]);
            while(st.size() >= 2 and st.back() <= st[st.size() - 2]) {
                st.pop_back();
            }
        }

        return st.size();
    }
};
