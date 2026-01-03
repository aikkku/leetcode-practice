class Solution {
public:
    int m, n;

    void drown(vector<vector<char>>& grid, int i, int j) {
        if(i < 0 or j < 0 or i >= m or j >= n
            or grid[i][j] == '0') return;
        
        grid[i][j] = '0';

        drown(grid, i + 1, j);
        drown(grid, i, j + 1);
        drown(grid, i - 1, j);
        drown(grid, i, j - 1);
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        m = grid.size();
        n = grid[0].size();

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '1') {
                    ans++;
                    drown(grid, i, j);
                }
            }
        }

        return ans;
    }
};
