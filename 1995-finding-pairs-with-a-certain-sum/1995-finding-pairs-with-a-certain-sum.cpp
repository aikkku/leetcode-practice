class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        this->nums1 = nums1;
        this->nums2 = nums2;
        for (int num : nums2) {
            freq[num]++;
        }
    }
    
    void add(int index, int val) {
        int oldVal = nums2[index];
        freq[oldVal]--;
        if (freq[oldVal] == 0) freq.erase(oldVal); 
        nums2[index] += val;
        freq[nums2[index]]++;
    }
    
    int count(int tot) {
        int ans = 0;
        for (int a : nums1) {
            int b = tot - a;
            if (freq.count(b)) {
                ans += freq[b];
            }
        }
        return ans;
    }

private:
    vector<int> nums1;
    vector<int> nums2;
    unordered_map<int, int> freq;
};