class Solution {
public:
    int maxDiff(int num) {
        string s(to_string(num));
        string maxs(s), mins(s);
        
        char c('9');
        for(int i = 0; i < maxs.size(); i++) {
            if(maxs[i] != c and c == '9') c = maxs[i];
            if(maxs[i] == c and c != '9') maxs[i] = '9';
        }

        bool b = 1;
        if(mins.size() > 1) {
            if(mins[0] == '1') {
                int i;
                for(i = 1; i < mins.size(); i++) {
                    if(mins[i] > '1') break;
                }
                if(i < mins.size()){
                    c = mins[i];
                    b = 0;
                } else c = ' ';
                
            } else {
                c = mins[0];
                b = 1;
            }
        } else c = mins[0];
        cout<<c;
        for(int i = 0; i < mins.size(); i++) {
            if(mins[i] == c) {
                if(b) mins[i] ='1';
                else mins[i] ='0';
            }
        }
        return stoi(maxs) - stoi(mins);
    }
};