class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int ans = 0;
        string first = x > y ? "ab" : "ba";
        string second = first == "ab" ? "ba" : "ab";

        string res = removeOcc(s, first);
        ans += (s.size() - res.size())/2 * max(x, y);


        s = res;
        res = removeOcc(s, second);
        ans += (s.size() - res.size())/2 * min(x, y);

        return ans;
    }

private:
    string removeOcc(string& s, string& c) {
        string res = "";
        stack<char> st;
        for(int i = 0; i < s.size(); i++) {
            if(s[i] == c[1] and st.size() > 0 and st.top() == c[0]) {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        while(!st.empty()) {
            res += st.top();
            st.pop();
        }

        reverse(res.begin(), res.end());
        return res;
    }

};