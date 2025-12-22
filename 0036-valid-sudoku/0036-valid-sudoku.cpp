class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //rows
        vector<vector<bool>> v(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(v[i][board[i][j] - '1']) return false;
                    else v[i][board[i][j] - '1'] = true;
                }
            }
        }
        cout<<1;

        //columns
        v = vector<vector<bool>>(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    if(v[j][board[i][j] - '1']) return false;
                    else v[j][board[i][j] - '1'] = true;
                }
            }
        }
        cout<<1<<endl;

        
        //boxes
        v = vector<vector<bool>>(9, vector<bool>(9, false));
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    cout<<i/3*3 + (j/3)<<' ';
                    if(v[i/3*3 + (j/3)][board[i][j] - '1']) return false;
                    else v[i/3*3 + (j/3)][board[i][j] - '1'] = true;
                }
            }
            cout<<endl;
        }

        return true;
    }
};