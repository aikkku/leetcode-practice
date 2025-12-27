class Solution {
public:
    vector<vector<int>> v;

    int solve(int i, int j, const string& text1, const string& text2) {
        if(i >= text1.size() or j >= text2.size()) return 0;
        if(v[i][j] != -1) return v[i][j];

        if(text1[i] == text2[j]) return v[i][j] = (1 + solve(i + 1, j + 1, text1, text2));
    
        
        return v[i][j] = max(solve(i + 1, j, text1, text2), solve(i, j + 1, text1, text2));
    }

    int longestCommonSubsequence(string text1, string text2) {
        v = vector<vector<int>>(text1.size(), vector<int>(text2.size(), -1));
        return solve(0, 0, text1, text2);
    }
};