class Solution {
public:
    bool canForm(vector<int>& nums, int p, int maxDiff) {
        int count = 0;
        for (int i = 0; i < nums.size() - 1;) {
            if (nums[i + 1] - nums[i] <= maxDiff) {
                count++;
                i += 2; 
            } else {
                i++;
            }
        }
        return count >= p;
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());

        int l = 0, r = nums.back() - nums.front();
        int answer = r;

        while(l <= r) {
            int mid = l + (r - l)/2;

            if(canForm(nums, p, mid)) {
                answer = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return answer;
    }
};