#include "../stdc++.h"

typedef pair<int, int> position;

class Solution {
public:
    // C1: DFS with flags copy array
    int uniquePathsIII(vector<vector<int>> &grid) {
        // Count total non-obstacle squares
        int nonObstacles = 0, currentTotalNonObstacles = 1, rows = grid.size(), columns = grid[0].size(), totalPaths = 0;
        vector<vector<int>> flags = vector<vector<int>>(rows, vector<int>(columns));
        position start;

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < columns; j++) {
                if (grid[i][j] != -1) {
                    nonObstacles++;
                }
                if (grid[i][j] == 1) {
                    start = position{i, j};
                    flags[i][j] = 1;
                }
            }
        }

        countThePaths(grid, flags, start, nonObstacles, currentTotalNonObstacles, totalPaths);

        return totalPaths;
    }

    vector<int> dx = vector<int>{-1, 0, 1, 0};
    vector<int> dy = vector<int>{0, 1, 0, -1};

    void countThePaths(vector<vector<int>> &grid,
                       vector<vector<int>> &flags,
                       position &currPosition,
                       const int &totalNonObstacles,
                       int &currentTotalNonObstacles,
                       int &totalPaths) {
        if (currentTotalNonObstacles == totalNonObstacles && grid[currPosition.first][currPosition.second] == 2) {
            totalPaths++;
        }

        for (int i = 0; i < dx.size(); i++) {
            auto newPosition = position{currPosition.first + dx[i], currPosition.second + dy[i]};

            if (canGoTo(grid, flags, newPosition)) {
                flags[newPosition.first][newPosition.second] = 1;
                currentTotalNonObstacles++;

                countThePaths(grid, flags, newPosition, totalNonObstacles, currentTotalNonObstacles, totalPaths);

                currentTotalNonObstacles--;
                flags[newPosition.first][newPosition.second] = 0;
            }
        }
    }

    bool canGoTo(vector<vector<int>> &grid, vector<vector<int>> &flags, position newPosition) {
        int rows = grid.size(), columns = grid[0].size();
        int i = newPosition.first, j = newPosition.second;
        return i >= 0 && i < rows && j >= 0 && j < columns && grid[i][j] != -1 && flags[i][j] != 1;
    }



    // C2: DFS shorter with:
    // + Reduce flags array
    // + Reduce unused variable & for loop: dx, dy, currentTotalNonObstacles, newPosition, ...
    int cnt=0,c=0;
    void dfs(vector<vector<int>>& grid,int x,int y,int c){

        if(x<0 || x>=grid.size() || y<0 || y>=grid[0].size() || grid[x][y]==-1)
            return;

        if(grid[x][y]==2){
            if(c==0)
                cnt++;
            return;
        }

        grid[x][y]=-1;
        dfs(grid,x+1,y,c-1);
        dfs(grid,x-1,y,c-1);
        dfs(grid,x,y+1,c-1);
        dfs(grid,x,y-1,c-1);
        grid[x][y]=0;

    }

    int uniquePathsIIIC2(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();
        int x,y;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    x=i;
                    y=j;
                }else if(grid[i][j]==0){
                    c++;
                }
            }
        }
        dfs(grid,x,y,c+1);

        return cnt;
    };
};