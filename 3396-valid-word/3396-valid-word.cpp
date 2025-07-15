class Solution {
public:
    bool isValid(string word) {
        if(word.size() < 3) return false;
        int n = 0;
        int v = 0;
        for(int i = 0; i < word.size(); i++) {
            if(isalnum(word[i])) {
                if(word[i] <= '9') n++;
                else if(tolower(word[i]) == 'a' or tolower(word[i]) == 'e' or tolower(word[i]) == 'i' or tolower(word[i]) == 'o' or tolower(word[i]) == 'u') v++;
            } else return false;
        }
        // cout<<n<<' '<<v<<' '<<word.size() - n - v;
        return (word.size() - n - v > 0) && v ;
    }
};