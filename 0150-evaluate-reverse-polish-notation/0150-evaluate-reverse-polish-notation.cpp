class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int ans = 0;
        for(int i = 0; i < tokens.size(); i++) {
            if((tokens[i][0] >= '0' and tokens[i][0] <= '9') or tokens[i].size() > 1) {
                st.push(stoi(tokens[i]));
            } else {
                ans = st.top();
                st.pop();
                if(tokens[i][0] == '+') {
                    ans = st.top() + ans;
                } else if(tokens[i][0] == '-') {
                    ans = st.top() - ans;
                } else if(tokens[i][0] == '*') {
                    ans = st.top() * ans;
                } else {
                    ans = st.top() / ans;
                }
                st.pop();
                st.push(ans);
            }
        }
        return st.top();
    }
};