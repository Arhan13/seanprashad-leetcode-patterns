class Solution{
    vector<vector<int>> moves = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    string movesValues = "DURL";
    int moveSize = 4;
    public:
    /*The lines maze[row][col] = 0; and maze[row][col] = 1; are used for backtracking in the code.
    When maze[row][col] = 0; is executed, it marks the current cell as visited or "blocked" in the maze. This is done to ensure that the current cell is not visited again during the exploration of other paths. It prevents infinite loops and ensures that each cell is visited at most once.
    After exploring all possible paths from the current cell and its neighboring cells, when the function returns from the recursive call, maze[row][col] = 1; is executed. 
    This restores the original value of the current cell to indicate that it is unvisited or "open" in the maze. 
    This allows the code to backtrack to this cell and explore other possible paths that might have been blocked by visiting this cell previously.
    By marking cells as visited (maze[row][col] = 0;) and restoring them to their original state (maze[row][col] = 1;), the backtracking algorithm ensures that all possible paths in the maze are explored without revisiting the same cell multiple times and without missing any valid paths.
    */
    void pathHelper(vector<string>& ans, vector<vector<int>> maze, int matrixSize, int row, int col, string currentPath){
        //Check if the tile is valid
        if(row<0 || col<0 || row>=matrixSize || col>=matrixSize || maze[row][col] == 0){
            return;
        }
        //Check if the tile is the destination 
        if(row == matrixSize-1 && col == matrixSize-1){
            ans.push_back(currentPath);
            return;
        }
        //Backtracking 
        maze[row][col] = 0;
        for(int i=0; i<moveSize; i++){
            pathHelper(ans, maze, matrixSize, row + moves[i][0], col + moves[i][1], currentPath + movesValues[i]);
        }
        maze[row][col] = 1;
        return;
    }
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        
        vector<string> ans;
        pathHelper(ans, m, n, 0, 0, "");
        return ans;
        
    }
};