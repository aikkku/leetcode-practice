class Solution {
public:
    vector<vector<int>> dp;
    string text1;
    string text2;
    int solve(int i, int j){
        if(i >= text1.size() or j >= text2.size()) return 0;
        if(text1[i] == text2[j]) {
            return dp[i][j] = 1 + solve(i + 1, j + 1);
        }
        if(dp[i][j] == -1) dp[i][j] = max(solve(i+1, j), solve(i, j+1));
        return dp[i][j];
    }

    int longestCommonSubsequence(string text1, string text2) {
        dp.resize(text1.size(), vector<int>(text2.size(), -1));
        this->text1 = text1;
        this->text2 = text2;
        return solve(0, 0);
    }
};