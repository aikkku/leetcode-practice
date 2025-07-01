class Solution {
public:
    int possibleStringCount(string word) {
        int ans = 1;
        for(int i = word.length() - 2; i > -1; i--) {
            if(word[i] == word[i+1]){
                ans++;
            
            }
        }
        return ans;
    }
};