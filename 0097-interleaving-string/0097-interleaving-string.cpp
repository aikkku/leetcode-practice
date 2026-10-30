class Solution {
public:
    string str1, str2, str3;

    map<tuple<int, int, int>, bool> memo;

    bool helper(int i, int j, int k) {
        if (memo.contains({i, j, k}))
            return memo[{i, j, k}];
        if (i == str1.size() and j == str2.size() and k == str3.size())
            return memo[{i, j, k}] = true;

        if ((i >= str1.size() or str3[k] != str1[i]) and
            (j >= str2.size() or str3[k] != str2[j])) {
            return memo[{i, j, k}] = false;
        } else {
            return memo[{i, j, k}] =
                       ((i < str1.size() and str3[k] == str1[i]) &&
                        helper(i + 1, j, k + 1)) ||
                       ((j < str2.size() and str3[k] == str2[j]) &&
                        helper(i, j + 1, k + 1));
        }
    }

    bool isInterleave(string s1, string s2, string s3) {
        str1 = s1, str2 = s2, str3 = s3;

        return helper(0, 0, 0);
    }
};