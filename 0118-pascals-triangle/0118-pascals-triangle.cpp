class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans = {{1}};
        if(numRows >= 2){
            ans.push_back({1, 1});
        }

        for(int i = 0; i < numRows - 2; i++){
            ans.push_back({1});
            for(int j = 1; j < i+2; j++){
                ans[i+2].push_back(ans[i+1][j] + ans[i+1][j-1]);
            }
            ans[i+2].push_back(1);
        }
        return ans;
    }
};