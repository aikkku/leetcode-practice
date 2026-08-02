class Solution {
   public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' or s[i] == '{' or s[i] == '[') {
                st.push(s[i]);
            } else {
                if (st.empty() or abs(s[i] - st.top()) > 2) return false;
                st.pop();
            }
        }
        return st.empty();
    }
};
