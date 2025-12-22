class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 0;
        vector<int> suf(n);
        suf[n - 1] = nums[n - 1];
        for(int i = n - 2; i > -1; i--) {
            suf[i] = suf[i + 1] + nums[i];
        }
        if(suf[1] == 0) return 0;
        int cur = 0;
        
        for(int i = 0; i < n - 1; i++) {
            if(cur == suf[i + 1]) return i;
            cur+= nums[i];
            cout<<cur<<' '<<suf[i + 1];
        }
        if(cur == 0) return n - 1;

        return -1;
    }

};