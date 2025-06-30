class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = 0, c = 0, rr = grid.size() - 1, cc = grid[0].size() - 1;
        if(grid[0][0] == 1 or grid[rr][cc] == 1) return -1;

        vector<pair<int,int>> d = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, -1}, {1, 1}, {-1, -1}, {-1, 1}};

        queue<pair<int,int>> q;
        q.push({0, 0});

        int l = 1;

        while(!q.empty()) {
            int ql = q.size();
            while(ql--) {
                r = q.front().first;
                c = q.front().second;
                q.pop();

                if(r == rr and c == cc) return l;

                for(pair<int, int> p : d) {
                    if(min(r + p.first, c + p.second) < 0 or r + p.first > rr or c + p.second > cc or grid[r + p.first][c + p.second] == 1) {
                        continue;
                    }
                    q.push({r + p.first, c + p.second});
                    grid[r + p.first][c + p.second] = 1;
                }
            }
            
            l++;
        }

        return -1;
    }
};