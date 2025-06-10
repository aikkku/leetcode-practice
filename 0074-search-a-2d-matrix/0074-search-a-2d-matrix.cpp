class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size()*matrix[0].size() - 1;

        while(l <= r) {
            int mid = (l+r) / 2;
            int a = mid/matrix[0].size(), b = mid%matrix[0].size();

            if(matrix[a][b] == target) return 1;
            else if(matrix[a][b] > target) r = mid - 1;
            else l = mid + 1;
        }
        return 0;
    }
};
