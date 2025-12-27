class Solution {
public:
    int rob(vector<int>& nums) {
        int no_rob = 0;
        int rob = 0;

        for(int i = 0; i < nums.size(); i++) {
            if(rob + nums[i] > no_rob) {
                int temp = no_rob;
                no_rob = rob + nums[i];
                rob = temp;
            } else {
                rob = max(rob, no_rob);
                no_rob = rob;
            }
        }

        return max(rob, no_rob);
    }
};
