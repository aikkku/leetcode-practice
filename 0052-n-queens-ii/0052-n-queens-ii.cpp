class Solution {
public:
    vector<vector<string>> ans;
    vector<string> board;


    bool check(int r, int c) {
        //column
        for(int i = 0; i < board.size(); i++) {
            if(i == r) continue;
            if(board[i][c] == 'Q') return false; 
        }

        
        //left-top to right-bottom
        int i = r, j = c;
        i--;
        j--;
        while(i > -1 and j > -1) {
            if(board[i][j] == 'Q') return false;
            i--;
            j--;
        }

        i = r, j = c;
        i++;
        j++;
        while(i < board.size() and j < board.size()) {
            if(board[i][j] == 'Q') return false;
            i++;
            j++;
        }


        //left-bottom to right-top
        i = r, j = c;
        i--;
        j++;
        while(i > -1 and j < board.size()) {
            if(board[i][j] == 'Q') return false;
            i--;
            j++;
        }

        i = r, j = c;
        i++;
        j--;
        while(i < board.size() and j > -1) {
            if(board[i][j] == 'Q') return false;
            i++;
            j--;
        }

        return true;
    }

    void solve(int r) {
        if(r == board.size()) {
            ans.push_back(board);
            return;
        }

        for(int i = 0; i < board.size(); i++) {
            if(check(r, i)) {
                board[r][i] = 'Q';
                solve(r+1);
                board[r][i] = '.';
            }
        }
    }


    int totalNQueens(int n) {
        board = vector<string>(n, string(n, '.'));

        cerr<<1;

        solve(0);

        return ans.size();
    }
};