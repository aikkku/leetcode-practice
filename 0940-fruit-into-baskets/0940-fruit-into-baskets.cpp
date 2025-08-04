class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int last = -1, secondLast = -1;
        int lastCount = 0, curr = 0, ans = 0;

        for (int fruit : fruits) {
            if (fruit == last || fruit == secondLast) {
                curr++;
            } else {
                curr = lastCount + 1;
            }

            if (fruit == last) {
                lastCount++;
            } else {
                lastCount = 1;
                secondLast = last;
                last = fruit;
            }

            ans = max(ans, curr);
        }

        return ans;
    }
};
