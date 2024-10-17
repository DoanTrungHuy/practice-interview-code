class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        const int n = s.size();
        int ans = num;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(s[i], s[j]);
                ans = max(ans, stoi(s));
                swap(s[i], s[j]);
            }
        }
        
        return ans;
    }
};