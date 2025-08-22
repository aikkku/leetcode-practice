class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> ans, l;
        int g = 1;
        for(int i = nums.size()-1; i>0; i--) {
            l.push_back(g);
            g*= nums[i];
        }
        l.push_back(g);

        for(int i = 0; i<nums.size(); i++) {
            int m = 1;
            if(i > 0) m *= nums[i-1];
            nums[i] *= m;
            m*=l[l.size()-1-i];
            ans.push_back(m);
        }
        return ans;
    }
};