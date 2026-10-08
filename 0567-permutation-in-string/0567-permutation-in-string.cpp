class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size() > s2.size())
            return false;
        vector<int> c1(26, 0);
        vector<int> c2(26, 0);

        for (int i = 0; i < s1.size(); i++) {
            c1[s1[i] - 'a']++;
            c2[s2[i] - 'a']++;
        }

        int match = 0;
        int l = 0;

        for (int i = 0; i < 26; i++) {
            if (c1[i] == c2[i])
                match++;
        }

        for (int r = s1.size(); r < s2.size(); r++) {
            if (match == 26)
                return true;

            int ri = s2[r] - 'a';
            c2[ri]++;
            if (c1[ri] == c2[ri])
                match++;
            else if (c1[ri] == c2[ri] - 1)
                match--;

            int li = s2[l] - 'a';
            c2[li]--;
            if (c1[li] == c2[li])
                match++;
            else if (c1[li] == c2[li] + 1)
                match--;

            l++;
        }

        return match == 26;
    }
};
