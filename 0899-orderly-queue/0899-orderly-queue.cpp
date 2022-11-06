class Solution {
public:
    string orderlyQueue(string s, int k) {
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        string res = s;
        s += s;
        for (int i = 1; i < res.size(); ++i) {
            res = min(res, s.substr(i, res.size()));
        }
        return res;
    }
};