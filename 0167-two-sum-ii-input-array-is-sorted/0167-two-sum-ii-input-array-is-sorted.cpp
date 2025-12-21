class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int L = 0, R = numbers.size() - 1, temp;
        while(L < R) {
            temp = numbers[L] + numbers[R];
            if(temp == target) return {L+1, R+1};
            else if(temp < target) L++;
            else R--;
        }

        return {0,0};
    }
};
