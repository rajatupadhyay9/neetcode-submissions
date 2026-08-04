class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        int sq_rt = sqrt(n);
        vector<uint64_t> rows(n), cols(n), boxs(n);
        
        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                if(board[i][j] == '.') continue;
                size_t box_idx = (i/sq_rt)*sq_rt + j/sq_rt;
                uint64_t bit_val = (1 << (board[i][j] - '1'));

                if(rows[i] & bit_val
                    || cols[j] & bit_val
                    || boxs[box_idx] & bit_val)
                    return false;

                rows[i] |= bit_val;
                cols[j] |= bit_val;
                boxs[box_idx] |= bit_val;
            }
        }
        return true;
    }
};
