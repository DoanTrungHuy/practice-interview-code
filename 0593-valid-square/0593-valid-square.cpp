class Solution {
public:
    int diff(vector<int> &p1, vector<int> &p2) {
        int x1 = p1[0], y1 = p1[1];
        int x2 = p2[0], y2 = p2[1];
        return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
    }
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p;
        p.push_back(p1);
        p.push_back(p2);
        p.push_back(p3);
        p.push_back(p4);
        unordered_set<int> us;
        const int n = (int)p.size();
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                int len = diff(p[i], p[j]);
                if (len == 0) {
                    return false;
                }
                us.insert(len);
            }
        }
        return us.size() == 2;
    }
};