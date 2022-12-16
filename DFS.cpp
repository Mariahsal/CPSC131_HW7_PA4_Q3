/**
 * PROBLEM 10: Number of Islands
 * MARIAH SALGADO
 * WILLIAM LUA
 **/
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        // m represents how many rows in the grid (HEIGHT)
        // n is the number of columns (WIDTH). The width is 0 if we are given an empty grid
        int m = grid.size(), n = m ? grid[0].size() : 0, islands = 0;
        // Looping through the entire grid
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '1') { // Checking if index i,j are adjacent to each other, If yes, then it's equal to 1
                    islands++;// Increment number of island 
                    eraseIslands(grid, i, j); // Removes element from container
                }
            }
        }
        return islands;//Return final answer
    }
private:
    void eraseIslands(vector<vector<char>>& grid, int i, int j) {
        int m = grid.size(), n = grid[0].size();// Getting height and width of the grid
        if (i < 0 || i == m || j < 0 || j == n || grid[i][j] == '0') { //Check if any of the values are greater than 0 or equal to 'm' and 'n',
            return;                                                    // If so, set gride to 0
        }
        grid[i][j] = '0';
        eraseIslands(grid, i - 1, j);// Looking UP 1 cell above as our starting point
        eraseIslands(grid, i + 1, j);// Looking DOWN 1 cell below as our starting point
        eraseIslands(grid, i, j - 1);// Looking LEFT 1 cell next to us as our starting point
        eraseIslands(grid, i, j + 1);// Looking RIGHT 1 cell next to us as our starting point
    }
};
