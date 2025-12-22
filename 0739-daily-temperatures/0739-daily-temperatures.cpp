class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int> st;
        vector<int> ans(t.size());
        for(int i = 0; i < t.size(); i++) {
            while(!st.empty() and t[st.top()] < t[i]) {
                ans[st.top()] = i - st.top();
                st.pop();
            }
            st.push(i);
        }

        while(!st.empty()) {
            ans[st.top()] = 0;
            st.pop();
        }

        return ans;
    }
};