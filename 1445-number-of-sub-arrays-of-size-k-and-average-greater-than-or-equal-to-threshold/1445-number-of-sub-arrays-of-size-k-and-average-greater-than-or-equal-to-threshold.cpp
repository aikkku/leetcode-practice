class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        int count = 0;
        int prev = 0;
        for(int i = 0; i < k; i++) {
            prev += arr[i];
        }

        count += ((prev / k) >= threshold);

        for(int i = k; i < arr.size(); i++) {
            prev += arr[i];
            prev -= arr[i - k];
            count += ((prev / k) >= threshold);
        }

        return count;
        
    }
};