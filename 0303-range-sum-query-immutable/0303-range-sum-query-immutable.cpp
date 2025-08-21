class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            prefix.push_back(nums[i] + prefix[i - 1]);
        }
    }
    
    int sumRange(int left, int right) {
        return prefix[right] - (left == 0? 0 : prefix[left - 1]);
    }

private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */