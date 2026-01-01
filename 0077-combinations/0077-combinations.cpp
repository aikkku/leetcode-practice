class Solution {
public:
    vector<vector<int>> ans;
    int gn;
    int gk;

    void solve(int i, vector<int> curComb) {
        
        if(curComb.size() == gk) {
            ans.push_back(curComb);
            return;
        }

        if(i > gn) return;

        for(int j = i; j < gn + 1; j++) {
            curComb.push_back(j);
            solve(j + 1, curComb);
            curComb.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        gn = n;
        gk = k;
        solve(1, {});
        return ans;
    }
};