class Solution {
public:
    string largestGoodInteger(string num) {
        int g = 1;
        string ans = "";
        for(int i = 1; i < num.size(); i++) {
            if(num[i] == num[i-1]) {
                g++;
                if(g == 3 and (ans.empty() or ans[0] < num[i])) {
                    ans = num[i];
                    ans += ans;
                    ans += ans[0];
                }
            } else {
                g = 1;
            }
        }

        return ans;
    }
};