class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid, queue<pair<int,int>>& q) {
        if(q.empty()) return 0;
        int rr = grid.size() - 1, cc = grid[0].size() - 1;

        vector<pair<int,int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

        int l = -1;
        int r, c;

        while(!q.empty()) {
            int ql = q.size();
            while(ql--) {
                r = q.front().first;
                c = q.front().second;
                q.pop();

                for(pair<int, int> p : d) {
                    if(min(r + p.first, c + p.second) < 0 or r + p.first > rr or c + p.second > cc or grid[r + p.first][c + p.second] != 1) {
                        continue;
                    }
                    q.push({r + p.first, c + p.second});
                    grid[r + p.first][c + p.second] = 0;
                }
            }
            
            l++;
        }

        return l;
    }

    int orangesRotting(vector<vector<int>>& grid) {
        int ans = 0;
        queue<pair<int,int>> q;

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 2) q.push({i, j});
            }
        }

        ans += shortestPathBinaryMatrix(grid,q);

        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1) return -1;
            }
        }

        return ans;
    }
};
