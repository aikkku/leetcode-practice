class Solution {
public:
    string w1, w2;

    map<pair<int, int>, int> memo;

    int helper (int i, int j) {
        if(memo.contains({i,j})) return memo[{i, j}];
        if(i < w1.size() and j < w2.size()) {
            if(w1[i] == w2[j]) {
                return memo[{i,j}] = helper (i + 1, j + 1);
            } else {
                return memo[{i,j}] = 1 + min(helper(i + 1, j + 1), 
                                            min(    helper(i, j + 1), 
                                                    helper(i + 1, j)
                                            )
                                        );
            }
        } else {
            return max(w1.size() - i, w2.size() - j);
        }
    }


    int minDistance(string word1, string word2) {
        w1 = word1;
        w2 = word2;

        return helper(0, 0);
    }
};
