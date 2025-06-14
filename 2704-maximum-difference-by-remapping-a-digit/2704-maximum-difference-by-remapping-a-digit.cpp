class Solution {
public:
    int minMaxDifference(int num) {
        string s(to_string(num));
        string maxs(s), mins(s);
        
        char c('9');
        for(int i = 0; i < maxs.size(); i++) {
            if(maxs[i] != c and c == '9') c = maxs[i];
            if(maxs[i] == c and c != '9') maxs[i] = '9';
        }

        c = mins[0];
        for(int i = 0; i < mins.size(); i++) {
            if(mins[i] == c) mins[i] ='0';
        }
        return stoi(maxs) - stoi(mins);
    }
};