class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int n = operations.size();
        vector<long long> lengths(n + 1);
        lengths[0] = 1; 

        // Step 1: Simulate forward to compute lengths after each operation
        for (int i = 0; i < n; ++i) {
            if (operations[i] == 0) {
                lengths[i + 1] = lengths[i] * 2;
            } else {
                lengths[i + 1] = lengths[i] * 2;
            }
            if (lengths[i + 1] >= k) {
                n = i + 1; 
                break;
            }
        }

        int shift = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (operations[i] == 0) {
                if (k > lengths[i]) {
                    k -= lengths[i]; 
                }
            } else {
                if (k > lengths[i]) {
                    k -= lengths[i];
                    shift = (shift + 1) % 26;
                }
            }
        }

        return 'a' + shift;
    }
};