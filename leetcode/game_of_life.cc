class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size();
        int n = board[0].size();
        
        vector<vector<int>> temp_outer;
        temp_outer.reserve(m);
        
        for(int i = 0; i<m; i++){
            vector<int> temp;
            temp.reserve(n);
            for(int j = 0; j < n; ++j){
                temp.push_back(findUpdate(board, i, j, n, m));
            }
            temp_outer.push_back(temp);
        }
        
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                board[i][j] = temp_outer[i][j];
            }
        }
    }
    
    int findUpdate(vector<vector<int>>& board, int row, int col, int n, int m){
        int live_neighbours = 0;
        // For the upper row
        if((row - 1) >= 0){
            if((col-1) >= 0){
                live_neighbours += board[row-1][col-1];
            }
            live_neighbours += board[row-1][col];
            if((col+1) < n){
                live_neighbours += board[row - 1][col+1];
            }
        }
        
        // For the current row
        if(col-1 >= 0){
            live_neighbours += board[row][col-1];
        }
        //live_neighbours += board[row][col];
        if(col + 1 < n){
            live_neighbours += board[row][col+1];
        }
        
        // For the next row
        if(row + 1 < m){
            if(col - 1 >= 0){
                live_neighbours += board[row+1][col-1];
            }
            live_neighbours += board[row+1][col];
            if(col + 1 < n){
                live_neighbours += board[row+1][col+1];
            }
        }
        
        if(board[row][col] == 1){
            if(live_neighbours < 2 || live_neighbours > 3){
                return 0;
            }
            return 1;
        }else{
            if(live_neighbours == 3){
                return 1;
            }
            return 0;
        }
    }
};
