class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        if(k > arr.size()) return 0;
        int window_sum = 0;
        int L = 0;
        int ans = 0;
        for(int i = 0; i < k - 1; i++) {
            window_sum += arr[i];
        }

        for(int R = k - 1; R < arr.size(); R++) {
            if(R - L + 1 > k) {
                window_sum -= arr[L];
                L++;
            }

            window_sum += arr[R];
            if(window_sum * 1.0 / (R - L + 1) >= threshold) ans++;
        }

        return ans;
    }
};