class Solution {
public:
    int maximumBags(vector<int>& c, vector<int>& r, int a) {
        int cnt = 0;
        vector<pair<int, int>> v;
        int n = c.size();
        v.resize(n);
        for (int i = 0; i < n; ++i)
        {
            v[i] = make_pair(c[i], r[i]);
        }
        sort(v.begin(), v.end(), [&](pair<int, int> a, pair<int, int> b){
            return a.first - a.second < b.first - b.second;
        });
        for (int i = 0; i < n; ++i)
        {
            if (v[i].first - v[i].second > 0)
            {
                a -= v[i].first - v[i].second;
            }
            if (a < 0)
            {
                break;
            }
            cnt++;
        }
        return cnt;
    }
};