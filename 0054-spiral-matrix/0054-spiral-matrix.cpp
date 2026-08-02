class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;

        int left = 0;
        int right = matrix[0].size() - 1;

        int top = 0;
        int bottom = matrix.size() - 1;

        while (left <= right and top <= bottom) {
            for (int i = left; i <= right; i++) {
                ans.push_back(matrix[top][i]);
            }

            for (int i = top + 1; i <= bottom; i++) {
                ans.push_back(matrix[i][right]);
            }

            if (top < bottom) {
                for (int i = right - 1; i >= left; i--) {
                    ans.push_back(matrix[bottom][i]);
                }
            }

            if (left < right) {
                for (int i = bottom - 1; i > top; i--) {
                    ans.push_back(matrix[i][left]);
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return ans;
    }
};