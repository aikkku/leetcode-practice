class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int s = nums[0];
        int f = nums[nums[0]];

        while(s != f) {
            s = nums[s];
            f = nums[nums[f]];
        }

        int ss = 0;

        while(s != ss) {
            s = nums[s];
            ss = nums[ss];
        }

        return s;
    }
};