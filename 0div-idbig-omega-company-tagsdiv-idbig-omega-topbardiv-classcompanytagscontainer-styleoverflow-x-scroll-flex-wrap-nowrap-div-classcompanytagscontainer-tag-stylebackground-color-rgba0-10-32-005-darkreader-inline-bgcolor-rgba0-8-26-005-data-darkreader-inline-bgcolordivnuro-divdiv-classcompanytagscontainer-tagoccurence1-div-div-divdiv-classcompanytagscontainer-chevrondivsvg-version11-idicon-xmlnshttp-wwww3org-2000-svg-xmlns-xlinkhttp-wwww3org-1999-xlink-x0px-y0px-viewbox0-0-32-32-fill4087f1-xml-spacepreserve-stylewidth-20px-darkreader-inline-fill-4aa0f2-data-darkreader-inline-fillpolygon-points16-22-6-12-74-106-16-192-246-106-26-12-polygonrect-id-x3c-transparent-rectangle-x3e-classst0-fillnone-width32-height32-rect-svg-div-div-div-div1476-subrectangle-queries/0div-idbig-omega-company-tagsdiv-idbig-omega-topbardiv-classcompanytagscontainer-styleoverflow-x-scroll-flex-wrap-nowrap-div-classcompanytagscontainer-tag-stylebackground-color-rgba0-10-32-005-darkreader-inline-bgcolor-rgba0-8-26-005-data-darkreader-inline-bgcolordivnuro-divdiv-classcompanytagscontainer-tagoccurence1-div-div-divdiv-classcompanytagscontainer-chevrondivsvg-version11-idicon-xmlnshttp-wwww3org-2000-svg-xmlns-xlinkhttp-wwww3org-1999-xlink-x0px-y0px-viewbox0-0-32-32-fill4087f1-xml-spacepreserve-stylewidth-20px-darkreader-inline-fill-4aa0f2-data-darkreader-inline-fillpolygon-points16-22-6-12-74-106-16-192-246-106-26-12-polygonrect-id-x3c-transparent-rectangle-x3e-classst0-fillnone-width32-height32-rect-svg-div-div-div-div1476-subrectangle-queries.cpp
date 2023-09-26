class SubrectangleQueries {
private:
    int n, m;
    vector<vector<long long>> bit;
    vector<vector<int>> rectangle;
    
public:
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        this->rectangle = rectangle;
        this->n = rectangle.size(), this->m = rectangle[0].size();
        bit.resize(n + 1, vector<long long>(m + 1, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                update(i, j, rectangle[i][j]);
            } 
        }
    }
    
    void update(int i, int j, int v) {
        for (int x = i + 1; x <= n; x += x&-x) {
            for (int y = j + 1; y <= m; y += y&-y) {
                bit[x][y] += v;
            }
        }
    }
    
    void updateSubrectangle(int row1, int col1, int row2, int col2, int newValue) {
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                update(i, j, -rectangle[i][j]);
            }
        }
        for (int i = row1; i <= row2; ++i) {
            for (int j = col1; j <= col2; ++j) {
                rectangle[i][j] = newValue;
                update(i, j, newValue);
            }
        }
    }
    
    long long get_sum(int i, int j) {
        long long res = 0;
        for (int x = i + 1; x > 0; x -= x&-x) {
            for (int y = j + 1; y > 0; y -= y&-y) {
                res += bit[x][y];
            }
        }
        return res;
    }
    
    int getValue(int row, int col) {
        return get_sum(row, col) - get_sum(row, col - 1) - get_sum(row - 1, col) + get_sum(row - 1, col - 1);
    }
};

/**
 * Your SubrectangleQueries object will be instantiated and called as such:
 * SubrectangleQueries* obj = new SubrectangleQueries(rectangle);
 * obj->updateSubrectangle(row1,col1,row2,col2,newValue);
 * int param_2 = obj->getValue(row,col);
 */