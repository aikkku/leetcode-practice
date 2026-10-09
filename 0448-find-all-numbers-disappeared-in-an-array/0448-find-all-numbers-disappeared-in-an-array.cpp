class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;
        vector<int> temp = nums;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[temp[i] - 1] > 0)
                nums[temp[i] - 1] = -nums[temp[i] - 1];
        }

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
            cout << nums[i] << ' ';
        }

        return ans;
    }
};