class Solution {
public:

    bool isValidDiagonal(
        vector<vector<char>>& grid, 
        int currentRow, 
        int currentCol, 
        int gridSize
        ){
        int i = currentRow;
        int j = currentCol;
        //Check top left 
        while(i>=0 && j>=0){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;j--;
        }
        i = currentRow;
        j = currentCol;
        //Check top right 
        while(i>=0 && j<gridSize){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i--;j++;
        }
        i = currentRow;
        j = currentCol;
        //Check bottom left 
        while(i<gridSize && j>=0){
            if(grid[i][j] == 'Q'){
                return false;
            }
            i++;j--;
        }
        i = currentRow;
        j = currentCol;
        //Check bottom right
        while(i<gridSize && j<gridSize){
            if(grid[i][j] == 'Q'){
                return true;
            }
            i++;j++;
        }
        return true;
    }
    bool isValidCol(vector<vector<char>>& grid, int currentCol, int gridSize){
        for(int i=0; i<gridSize; i++){
            if(grid[i][currentCol] == 'Q'){
                return false;
            }
        }
        return true;
    }
    bool isValidRow(vector<vector<char>>& grid, int currentRow, int gridSize){
        for(int i=0; i<gridSize; i++){
            if(grid[currentRow][i] == 'Q'){
                return false;
            }
        }
        return true;
    }
    bool isValid(vector<vector<char>>& grid, int currentRow, int currentCol, int gridSize){
        return isValidRow(grid, currentRow, gridSize) && isValidCol(grid, currentCol, gridSize) && isValidDiagonal(grid, currentRow, currentCol, gridSize);
    }
    vector<string> formatGrid(vector<vector<char>>& grid, int gridSize){
        vector<string> result;
        for(int i=0;i<gridSize;i++){
            string temp = "";
            for(int j=0;j<gridSize;j++){
                temp += grid[i][j];
            }
            result.push_back(temp);
        }
        return result;
    }
    void solve(
        vector<vector<char>>& grid, 
        vector<vector<string>>& ans, 
        int gridSize,
        int currentRow
        ){
        //If currentRow crosses the size limit
        if(currentRow == gridSize){
            vector<string> tempGrid = formatGrid(grid, gridSize);
            ans.push_back(tempGrid);
            return;
        }
        //Check if the queen placement is valid for each col
        for(int currentCol = 0; currentCol<gridSize; currentCol++){
            if(isValid(grid, currentRow, currentCol, gridSize)){
                grid[currentRow][currentCol] = 'Q';
                solve(grid, ans, gridSize, currentRow + 1);// Increment the currentRow value
                grid[currentRow][currentCol] = '.';
            }
        }
        

    }
    vector<vector<string>> solveNQueens(int n) {
        //Back tracking case if where we put the queen and move ahead or we move ahead without the queen
        vector<vector<string>> ans;
        //Creating a grid
        vector<vector<char>> grid(n, vector<char> (n, '.'));
        solve(grid, ans, n, 0);
        return ans;
    }
};