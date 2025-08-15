class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n>0){
            double d = log(n*1.0)/log(4.0);
            return fabs(d - round(d)) < 1e-10;
        } return 0;
    }
};