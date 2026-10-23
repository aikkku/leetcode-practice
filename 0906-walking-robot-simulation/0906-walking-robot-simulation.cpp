class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        unordered_set<long long> obstacleSet;

        auto encode = [](int x, int y) -> long long {
            return (static_cast<long long>(x) + 30000) * 60001 + (y + 30000);
        };

        for (const auto& obstacle : obstacles) {
            obstacleSet.insert(encode(obstacle[0], obstacle[1]));
        }

        int x = 0, y = 0;
        int ans = 0;

        vector<vector<int>> direction = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

        int d = 0;

        for (int command : commands) {
            if (command == -1) {
                d = (d + 1) % 4;
            } else if (command == -2) {
                d = (d + 3) % 4;
            } else {
                for (int j = 0; j < command; j++) {
                    int nx = x + direction[d][0];
                    int ny = y + direction[d][1];

                    if (obstacleSet.count(encode(nx, ny))) {
                        break;
                    }

                    x = nx;
                    y = ny;

                    ans = max(ans, x * x + y * y);
                }
            }
        }

        return ans;
    }
};