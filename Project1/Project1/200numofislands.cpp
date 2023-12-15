class Solution {
public:
    vector<vector<int>> visited;
    int movX[4] = { 0, 1, 0, -1 };
    int movY[4] = { 1, 0, -1, 0 };
public:
    void makeVisited(vector<vector<char>>& grid) {
        for (int i = 0; i < grid.size(); ++i) {
            vector<int> temp;
            for (int j = 0; j < grid[i].size(); ++j) {
                temp.push_back(0);
            }
            visited.push_back(temp);
        }
    }
    void bfs(vector<vector<char>>& grid, int i, int j) {
        queue<pair<int, int>> next;
        next.push(make_pair(i, j));
        visited[i][j] = 1;
        while (next.size() > 0) {
            auto temp = next.front();
            next.pop();
            for (int i = 0; i < 4; ++i) {
                int newX = temp.first + movX[i];
                int newY = temp.second + movY[i];
                if (newX >= 0 && newX < grid.size()
                    && newY >= 0 && newY < grid[newX].size()
                    && grid[newX][newY] == '1' && visited[newX][newY] == 0) {
                    visited[newX][newY] = 1;
                    next.push(make_pair(newX, newY));
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        makeVisited(grid);
        int answer = 0;
        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[i].size(); ++j) {
                if (grid[i][j] == '1' && visited[i][j] == 0) {
                    bfs(grid, i, j);
                    ++answer;
                }
            }
        }
        return answer;
    }
};