class Solution {
public:
    int maxTurbulenceSize(vector<int>& arr) {
        int ans = 1, cur = 1;
        int id = 0;
        for(int i = 1; i < arr.size(); i++) {
            if(arr[i] == arr[i-1]) {
                cur = 1;
            } else if(arr[i] > arr[i-1]) {
                if(id == -1) {
                    cur++;
                } else cur = 2;
                id = 1;
            } else {
                if(id == 1) {
                    cur++;
                } else cur = 2;
                id = -1;
            }

            ans = max(cur, ans);
        }

        return ans;
    }
};