class Solution {
private:
    vector<vector<int>> p;
    vector<int> idx;
    int ans = 0;
    
public:
    void dfs(int i, int c) {
        if (c > 4) {
            return;
        }
        if (i == p.size()) {
            if (c == 4) {
                vector<vector<int>> rect;
                
                for (int j : idx) {
                    rect.push_back(p[j]);
                }
                
                sort(rect.begin(), rect.end());

                int x1 = rect[0][0], y1 = rect[0][1];
                int x2 = rect[3][0], y2 = rect[3][1];

                if (rect[0][0] == rect[1][0] && rect[2][0] == rect[3][0] && rect[0][1] == rect[2][1] && rect[1][1] == rect[3][1]) {
                    bool flag = true;
                    for (vector<int> t : p) {
                        if (t[0] >= x1 && t[0] <= x2 && t[1] >= y1 && t[1] <= y2) {
                            if (t != rect[0] && t != rect[1] && t != rect[2] && t != rect[3]) {
                                flag = false;
                                break;
                            }
                        }
                    }
                    if (flag) {
                        ans = max(ans, abs(x2 - x1) * abs(y2 - y1));
                    }
                }
            }
            return;
        }
        idx.push_back(i);
        dfs(i + 1, c + 1);
        idx.pop_back();
        dfs(i + 1, c);
    }
    
    int maxRectangleArea(vector<vector<int>>& p) {
        ans = -1;
        this->p = p;
        const int n = p.size();
        dfs(0, 0);
        return ans;
    }
};