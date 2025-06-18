class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i < nums.size(); i+=3) {
            vector<int> temp(3);
            for(int j = 0; j < 3; j++) {
                temp[j] = (nums[i + j]);
            }
            if(temp[2] - temp[0] > k) return {};
            else ans.push_back(temp);
        }

        return ans;
    }
};