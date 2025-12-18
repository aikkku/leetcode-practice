class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int temp = 0, ans = INT_MIN; 
        for(int R = 0; R < nums.size(); R++){
            if(temp < 0) {
                temp = 0;
            }
            temp += nums[R];
            ans = max(ans, temp);
        }
        return ans;
    }

};
