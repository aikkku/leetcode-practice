class Solution {
public:
    void drownTheIsland(vector<vector<char>>& grid, int r, int c) {
        if(r < 0 or r >= grid.size() or c < 0 or c >= grid[0].size() or grid[r][c] == '0') return;
        
        grid[r][c] = '0';

        drownTheIsland(grid, r + 1, c);
        drownTheIsland(grid, r - 1, c);
        drownTheIsland(grid, r, c + 1);
        drownTheIsland(grid, r, c - 1);

        return;
    }

    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == '1'){
                    ans++;
                    drownTheIsland(grid, i, j);
                }
            }
        }
        return ans;
    }
};
