class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int r = 0, c = 0;
        int rr = grid.size() - 1, cc = grid[0].size() - 1;
        if(grid[r][c] == 1 or grid[rr][cc] == 1) return -1;

        int l = 1;

        vector<pair<int, int>> dv = {
            {1, 0}, {0, 1},
            {-1, 0}, {0, -1},
            {1, 1}, {-1, -1},
            {1, -1}, {-1, 1},
        };

        set<pair<int, int>> visited;

        queue<pair<int, int>> q;
        q.push({0, 0});
        visited.insert({0, 0});
        while(!q.empty()) {
            int temp_size = q.size();

            while(temp_size--) {
                int cur_r = q.front().first, 
                    cur_c = q.front().second;
                
                q.pop();

                if(cur_r == rr and cur_c == cc) {
                    return l;
                }

                for(const pair<int, int>& d : dv) {
                    int new_r = cur_r + d.first,
                        new_c = cur_c + d.second;

                    if(min(new_r, new_c) < 0 
                        or new_r > rr or new_c > cc
                        or visited.count({new_r, new_c})
                        or grid[new_r][new_c] == 1) continue;

                    q.push({new_r, new_c});
                    visited.insert({new_r, new_c});
                }
            }

            l++;
        }

        return -1;
    }
};