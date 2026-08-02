class Solution {
public:
    string temp = "";

    void fillSpace(int n) {
        while (n--) {
            temp += ' ';
        }
    }

    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
        int i = 0;
        int count = 0;
        int count_i = 0;

        while (i < words.size()) {
            if (count + words[i].size() <= maxWidth - count_i) {
                count += words[i].size();
                count_i++;
                i++;
            } else {
                temp = "";
                if (count_i == 1) {
                    temp += words[i - 1];
                    count_i = 0;
                    fillSpace(maxWidth - temp.size());
                } else {
                    int totalSpaces = maxWidth - count;
                    int space = totalSpaces / (count_i - 1);
                    int left = totalSpaces % (count_i - 1);
                    int c = 1;
                    while (count_i > 0) {
                        temp += words[i - count_i];
                        if (count_i > 1) {
                            if (left > 0) {
                                left--;
                                fillSpace(space + 1);
                            } else {
                                fillSpace(space);
                            }
                        }

                        count_i--;
                    }
                }
                count = 0;
                count_i = 0;
                result.push_back(temp);
            }
        }
        if (count_i > 0) {
            temp = "";
            if (count_i == 1) {
                temp += words[i - 1];
                count_i = 0;
                fillSpace(maxWidth - temp.size());
            } else {
                int space = maxWidth - count - count_i + 1;
                while (count_i > 0) {
                    temp += words[i - count_i];
                    if (count_i > 1) {
                        fillSpace(1);
                    }
                    count_i--;
                }

                fillSpace(space);
            }
            result.push_back(temp);
        }

        return result;
    }
};