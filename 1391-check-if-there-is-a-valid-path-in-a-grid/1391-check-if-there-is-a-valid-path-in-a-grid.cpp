class Solution {
private:
    unordered_map<char, vector<int>> mapping;
    vector<vector<char>> DIR;
    vector<vector<bool>> visited;
    int n, m;

public:
    bool isValid(int x, int y) {
        return 0 <= x and x < n and 0 <= y and y < m;
    }
    
    bool dfs(vector<vector<int>>& grid, int x, int y) {
        if (x == n - 1 and y == m - 1) {
            return true;
        }
        
        visited[x][y] = true;
        
        for (char c : DIR[grid[x][y] - 1]) {
            int dx = mapping[c][0];
            int dy = mapping[c][1];

            int nx = x + dx;
            int ny = y + dy;

            if (!isValid(nx, ny) or visited[nx][ny]) {
                continue;
            }
            
            for (char b : DIR[grid[nx][ny] - 1]) {
                if (nx + mapping[b][0] == x and ny + mapping[b][1] == y) {
                    if (dfs(grid, nx, ny)) {
                        return true;
                    }
                }
            }
        }
        
        return false;
    }
    
    bool hasValidPath(vector<vector<int>>& grid) {
        mapping['l'] = {0, -1}, mapping['r'] = {0, 1};
        mapping['t'] = {-1, 0}, mapping['d'] = {1, 0};
        
        this->n = grid.size(), this->m = grid[0].size();
        
        DIR = {
            {'l', 'r'}, {'t', 'd'}, {'l', 'd'},
            {'r', 'd'}, {'l', 't'}, {'r', 't'}
        };
        
        visited.resize(n, vector<bool>(m, false));
        
        return dfs(grid, 0, 0);
    }
};