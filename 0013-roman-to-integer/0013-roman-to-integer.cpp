class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> mp = {{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};

        int ans = 0;

        for (int i = 0; i < s.size(); i++) {
            if ((i < s.size() - 1) and
                (s[i] == 'I' or s[i] == 'X' or s[i] == 'C')) {
                if (s[i] == 'I' and s[i + 1] == 'V') {
                    ans += 4;
                    i++;
                } else if (s[i] == 'I' and s[i + 1] == 'X') {
                    ans += 9;
                    i++;
                } else if (s[i] == 'X' and s[i + 1] == 'L') {
                    ans += 40;
                    i++;
                } else if (s[i] == 'X' and s[i + 1] == 'C') {
                    ans += 90;
                    i++;
                } else if (s[i] == 'C' and s[i + 1] == 'D') {
                    ans += 400;
                    i++;
                } else if (s[i] == 'C' and s[i + 1] == 'M') {
                    ans += 900;
                    i++;
                } else {
                    ans += mp[s[i]];
                }
            } else {
                ans += mp[s[i]];
            }
        }

        return ans;
    }
};