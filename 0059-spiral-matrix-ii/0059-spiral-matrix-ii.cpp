class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));

        int left = 0;
        int right = n - 1;

        int top = 0;
        int bottom = n - 1;

        int counter = 1;

        while (left <= right and top <= bottom) {
            for (int i = left; i <= right; i++) {
                matrix[top][i] = counter++;
            }

            for (int i = top + 1; i <= bottom; i++) {
                matrix[i][right] = counter++;
            }

            if (top < bottom) {
                for (int i = right - 1; i >= left; i--) {
                    matrix[bottom][i] = counter++;
                }
            }

            if (left < right) {
                for (int i = bottom - 1; i > top; i--) {
                    matrix[i][left] = counter++;
                }
            }

            left++;
            right--;
            top++;
            bottom--;
        }

        return matrix;
    }
};