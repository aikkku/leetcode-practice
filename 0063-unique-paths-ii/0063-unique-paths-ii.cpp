class Solution {
public:
    int rlim;
    int clim;

    int solve(vector<vector<int>>& obstacleGrid, vector<vector<int>>& v, int r, int c) {
        if(r == rlim or c == clim or obstacleGrid[r][c] == 1) return 0;
        if(v[r][c] > 0) return v[r][c];
        if(r == rlim - 1 and c == clim - 1) return 1;
        return v[r][c] = solve(obstacleGrid, v, r+1, c) + solve(obstacleGrid, v, r, c+1);
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        rlim = obstacleGrid.size();
        clim = obstacleGrid[0].size();
        vector<vector<int>> v(rlim, vector<int>(clim, 0));
        return solve(obstacleGrid, v, 0, 0);
    }
};