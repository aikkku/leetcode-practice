class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        bool plus = 0;
        for(int i = digits.size() - 1; i > -1; i--) {
            if(digits[i] == 9) {
                digits[i] = 0;
            } else {
                digits[i]++;
                plus = 1;
                break;
            }
        }
        if(!plus) {
            digits.insert(digits.begin(), 1);
            
        }
        return digits;


    }
};