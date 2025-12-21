class NumArray {
public:
    NumArray(vector<int>& nums) {
        prefix = vector<int>(nums.size() + 1);
        prefix[0] = 0;
        for(int i = 1; i < nums.size() + 1; i++) prefix[i] = prefix[i - 1] + nums[i - 1];
    }
    
    int sumRange(int left, int right) {
        return prefix[right + 1] - prefix[left];
    }

private:
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */