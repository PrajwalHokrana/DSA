class Solution {
public:
    bool isvalid(vector<vector<int>>& grid, int row, int col, int n, int expval) {
        if (row < 0 || col < 0 || row >= n || col >= n || grid[row][col] != expval) {
            return false;
        }

        if (expval == n*n-1)
        {
            return true;
        }

        if(isvalid(grid, row-2,col+1,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row-1,col+2,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row+1,col+2,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row+2,col+1,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row+2,col-1,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row+1,col-2,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row-1,col-2,n,expval+1))
        {
            return true;
        }
        if(isvalid(grid, row-2,col-1,n,expval+1))
        {
            return true;
        }

        return false;
    }

    bool checkValidGrid(vector<vector<int>>& grid) {
    
        return isvalid(grid, 0, 0,grid.size(),0);
    }
};