class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char, int> um;
        
        for (char c : s) {
            um[c]++;
        }
        
        unordered_set<int> us;
        int res = 0;
        
        for (auto &[v, c] : um) {
            while (c > 0 and us.count(c)) {
                c--;
                res++;
            }
            us.insert(c);
        }
        
        return res;
    }
};