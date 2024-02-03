using pr = pair<int, int>;

class Solution {
public:
    bool isTopLeft(pr tl, pr br) {
        return tl.first <= br.first and tl.second >= br.second;
    }

    bool isPInside(pr point, pr tl, pr br) {
        int x = point.first;
        int y = point.second;

        int x1 = tl.first;
        int y1 = tl.second;
        int x2 = br.first;
        int y2 = br.second;

        return x1 <= x and x <= x2 and y1 >= y and y >= y2;
    }

    int numberOfPairs(vector<vector<int>>& points) {
        const int n = points.size();
        vector<pr> pp;

        for (vector<int> p : points) {
            pp.push_back({p[0], p[1]});
        }

        int ans = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                
                if (i == j) {
                    continue;
                }

                if (isTopLeft(pp[i], pp[j])) {
                    bool check = true;

                    for (int k = 0; k < n; ++k) {
                        if (k == i or k == j) {
                            continue;
                        }

                        if (isPInside(pp[k], pp[i], pp[j])) {
                            check = false;
                            break;
                        }
                    }

                    ans += check;
                }
            }
        }

        return ans;
    }
};