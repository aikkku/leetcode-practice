class Solution {
public:
    int ans = 0;
    vector<vector<int>> events;
    vector<vector<int>> dp;
    int dfs(int k, int i) {
        if(i >= events.size() or k == 0) {
            return 0;
        }
        // cout<<i<<' '<<k<<endl;
        if(dp[i][k] != -1) return dp[i][k];
        else {
            int skip = dfs(k, i+1);

            int l = i;
            int r = events.size();
            while(l < r) {
                int mid = l + (r - l) / 2;

                if(events[mid][0] > events[i][1]) {
                    r = mid;
                } else l = mid + 1;
            }

            int take = events[i][2] + dfs(k - 1, l);
            return dp[i][k] = max(take, skip);
        }

    }

    int maxValue(vector<vector<int>>& event, int k) {
        sort(event.begin(), event.end());
        events = event;
        dp.resize(events.size() + 1, vector<int>(k + 1, -1));
        
        return dfs(k, 0);
    }
};