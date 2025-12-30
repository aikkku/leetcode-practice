class Solution {
public:
    vector<int> v;

    int solve(int n) {
        if(n == 0) return 0;
        if(n < 0) return 10000;
        if(v[n - 1] != -1) return v[n - 1];

        int ans = 10000;

        for(int i = 1; i * i <= n; i++) {
            ans = min(ans, 1 + solve(n - (i * i)));
        }

        return v[n - 1] = ans;
    }

    int numSquares(int n) {
        v = vector<int>(n, -1);

        return solve(n);
    }
};