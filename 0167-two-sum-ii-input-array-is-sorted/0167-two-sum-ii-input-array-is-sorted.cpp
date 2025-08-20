class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size() - 1;
        while(L < R) {
            if(target == numbers[L] + numbers[R]) return {L+1, R+1};
            else if(target > numbers[L] + numbers[R]) L++;
            else R--;
        }
        return {0, 0};
    }
};
