class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<long long>> v(m + 1, vector<long long>(n + 1, 0));

        v[m - 1][n] = 1;

        for(int i = m - 1; i > -1; i--) {
            for(int j = n - 1; j > -1; j--) {
                v[i][j] = (v[i + 1][j] + v[i][j + 1]);
                if(obstacleGrid[i][j] == 1) v[i][j] = 0;
            }
        }

        return v[0][0];
    }
};