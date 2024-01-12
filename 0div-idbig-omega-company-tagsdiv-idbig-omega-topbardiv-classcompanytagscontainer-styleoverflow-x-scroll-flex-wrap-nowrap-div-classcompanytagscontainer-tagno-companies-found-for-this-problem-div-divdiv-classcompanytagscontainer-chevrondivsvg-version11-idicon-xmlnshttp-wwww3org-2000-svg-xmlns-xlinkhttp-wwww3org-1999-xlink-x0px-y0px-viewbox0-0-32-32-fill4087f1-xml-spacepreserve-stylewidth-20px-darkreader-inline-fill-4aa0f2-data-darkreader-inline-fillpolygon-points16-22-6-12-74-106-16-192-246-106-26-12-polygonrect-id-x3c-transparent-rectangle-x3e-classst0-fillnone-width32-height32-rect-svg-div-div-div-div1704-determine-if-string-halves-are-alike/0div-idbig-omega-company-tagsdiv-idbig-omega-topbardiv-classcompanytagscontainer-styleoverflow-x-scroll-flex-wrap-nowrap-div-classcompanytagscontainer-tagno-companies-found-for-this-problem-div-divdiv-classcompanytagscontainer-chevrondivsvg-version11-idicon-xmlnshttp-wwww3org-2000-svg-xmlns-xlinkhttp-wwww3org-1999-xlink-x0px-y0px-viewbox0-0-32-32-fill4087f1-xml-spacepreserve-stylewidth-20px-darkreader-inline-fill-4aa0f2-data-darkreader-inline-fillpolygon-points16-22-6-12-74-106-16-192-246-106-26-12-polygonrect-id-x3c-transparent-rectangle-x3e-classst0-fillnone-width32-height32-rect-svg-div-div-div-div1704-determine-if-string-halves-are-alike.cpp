class Solution {
public:
    bool halvesAreAlike(string s) {
        int c1 = 0, c2 = 0;
        int n = s.size();
        int t = n / 2;
        unordered_set<int> us;
        for (char c : "ueoai") {
            us.insert(c);
            us.insert(toupper(c));
        } 
        for (int i = 0; i < t; ++i) {
            if (us.find(s[i]) != us.end()) {
                c1++;
            }
        }
        for (int i = t; i < n; ++i) {
            if (us.find(s[i]) != us.end()) {
                c2++;
            }
        }
        return c1 == c2;
    }
};