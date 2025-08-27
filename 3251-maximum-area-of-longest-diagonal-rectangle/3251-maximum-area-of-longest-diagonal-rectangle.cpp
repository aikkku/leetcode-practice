class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        double maxD = 0;
        int maxA = 1;

        for(vector<int> d : dimensions) {
            double c = sqrt((d[0] * d[0]) + (d[1] * d[1]));
            if(c > maxD or (fabs(c - maxD) < 1e-9 &&  d[0] * d[1] > maxA)) {
                maxD = c;
                maxA = d[0] * d[1];
            }
        }

        return maxA;
    }
};