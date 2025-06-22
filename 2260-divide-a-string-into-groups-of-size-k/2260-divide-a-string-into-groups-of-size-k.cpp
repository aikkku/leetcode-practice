class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int i = 0;
        string temp = "";
        while(i < s.length()) {
            if(temp.size() < k) {
                temp+=s[i];
            } else {
                ans.push_back(temp);
                temp = "";
                i--;
            }
            i++;
        }
        if(temp.size() > 0) {
            while(temp.size() < k) {
                temp += fill;
            }
            ans.push_back(temp);
        }

        return ans;
    }
};