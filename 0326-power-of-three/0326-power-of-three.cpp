class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n>0){
            double d = log(n*1.0)/log(3.0);
            return fabs(d - round(d)) < 1e-10;
        } return 0;
    }
};