class Solution {
public:
    string makeGood(string s) {
        while (true) {
            bool check = true;
            int n = s.size();
            for (int i = 0; i < n - 1; ++i) {
                if (abs(s[i] - s[i + 1]) == 32) {
                    s.erase(s.begin() + i);
                    s.erase(s.begin() + i);
                    check = false;
                    break;
                }
            }
            if (check) {
                break;
            }
        }
        return s;
    }
};