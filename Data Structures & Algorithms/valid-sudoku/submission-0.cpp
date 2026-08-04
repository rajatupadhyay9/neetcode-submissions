class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        vector<vector<int>>
            rows(n, vector<int>(n, 0)),
            cols(n, vector<int>(n, 0)),
            boxs(n, vector<int>(n, 0));
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') continue;
                int int_val = board[i][j] - '1';
                rows[i][int_val]++;
                cols[j][int_val]++;

                int sq_rt = sqrt(n);
                int which_box = (i/sq_rt)*sq_rt + j/sq_rt;
                boxs[which_box][int_val]++;
            }
        }

        for(int i=0; i<n; i++) {
            for(auto n: rows[i]) if(n > 1) return false;
            for(auto n: cols[i]) if(n > 1) return false;
            for(auto n: boxs[i]) if(n > 1) return false;
        }
        return true;
    }
};
