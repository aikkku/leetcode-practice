class Solution {
public:
    string s;
    int k;

    bool isValid(const string& t) {
        int i = 0, count = 0;
        for (char c : s) {
            if (c == t[i]) {
                i++;
                if (i == t.size()) {
                    i = 0;
                    count++;
                    if (count == k) return true;
                }
            }
        }
        return false;
    }

    string longestSubsequenceRepeatedK(string s, int k) {
        this->s = s;
        this->k = k;
        unordered_map<char, int> freq;
        for (char c : s) freq[c]++;

        string chars = "";
        for (char c = 'z'; c >= 'a'; --c) {
            if (freq[c] >= k) chars += c;
        }

        queue<string> q;
        string best = "";

        for (char c : chars) {
            string tmp(1, c);
            q.push(tmp);
            if (isValid(tmp)) {
                if (tmp.size() > best.size() || (tmp.size() == best.size() && tmp > best)) {
                    best = tmp;
                }
            }
        }

        while (!q.empty()) {
            string cur = q.front(); q.pop();
            if (cur.size() >= s.size() / k) continue;
            for (char c : chars) {
                string next = cur + c;
                if (isValid(next)) {
                    if (next.size() > best.size() || (next.size() == best.size() && next > best)) {
                        best = next;
                    }
                    q.push(next);
                }
            }
        }

        return best;
    }
};
