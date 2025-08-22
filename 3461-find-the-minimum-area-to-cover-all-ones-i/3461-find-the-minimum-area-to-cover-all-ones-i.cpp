class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int left = INT_MAX, right = INT_MIN, top = INT_MAX, bottom = INT_MIN;
        for(int i = 0; i < grid.size(); i++) {
            for(int j = 0; j < grid[0].size(); j++) {
                if(grid[i][j] == 1){
                    left = min(i, left);
                    top = min(j, top);
                    right = max(i, right);
                    bottom = max(j, bottom);
                }
            }
        }

        return (right - left + 1) * (bottom - top + 1);
    }
};