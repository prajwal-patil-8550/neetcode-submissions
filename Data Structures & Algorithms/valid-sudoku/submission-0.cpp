class Solution {
public:

    bool isSafe(char digit, int row, int col,vector<vector<char>>& board){
        for(int i=0; i<9; i++){
            if(i!=col && digit==board[row][i]){
                return false;
            }
        }
        //for column
        for(char i=0; i<9; i++){
            if(i!=row && digit==board[i][col]){
                return false;
            }
        }

        int sr=(row/3)*3;
        int sc=(col/3)*3;
        for(int i=sr; i<sr+3; i++){
            for(int j=sc; j<sc+3; j++){
                if((i != row || j != col) && board[i][j]==digit){
                    return false;
                }
            }
        }
        return true;
    }

    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){

                if(board[i][j] == '.')
                continue;

                if(! isSafe(board[i][j], i, j, board)){
                    return false;
                }
            }
        }
        return true;
    }
};
