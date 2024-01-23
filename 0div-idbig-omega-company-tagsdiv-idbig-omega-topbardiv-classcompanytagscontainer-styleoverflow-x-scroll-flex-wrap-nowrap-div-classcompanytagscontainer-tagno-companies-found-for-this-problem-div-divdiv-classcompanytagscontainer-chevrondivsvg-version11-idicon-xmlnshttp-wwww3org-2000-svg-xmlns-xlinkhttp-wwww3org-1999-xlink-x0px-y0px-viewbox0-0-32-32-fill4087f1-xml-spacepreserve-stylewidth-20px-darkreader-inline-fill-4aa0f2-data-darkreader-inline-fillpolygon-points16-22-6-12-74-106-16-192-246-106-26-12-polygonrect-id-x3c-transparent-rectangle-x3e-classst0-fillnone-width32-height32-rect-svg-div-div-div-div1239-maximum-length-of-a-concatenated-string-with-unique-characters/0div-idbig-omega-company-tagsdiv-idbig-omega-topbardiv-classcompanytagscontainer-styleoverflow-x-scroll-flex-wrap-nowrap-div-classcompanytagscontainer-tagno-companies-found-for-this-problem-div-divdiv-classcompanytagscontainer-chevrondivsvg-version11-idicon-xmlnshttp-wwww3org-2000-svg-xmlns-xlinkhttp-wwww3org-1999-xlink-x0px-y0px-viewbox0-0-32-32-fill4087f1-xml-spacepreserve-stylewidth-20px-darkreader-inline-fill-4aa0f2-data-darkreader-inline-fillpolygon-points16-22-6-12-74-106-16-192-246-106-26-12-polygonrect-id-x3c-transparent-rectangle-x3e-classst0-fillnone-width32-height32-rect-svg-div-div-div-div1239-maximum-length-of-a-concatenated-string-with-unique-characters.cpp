class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int ans = 0;
        
        for (int mask = 0; mask < (1 << n); ++mask) {
            int seen = 0, len = 0;
            bool flag = false;
            for (int i = 0; i < n; ++i) {
                if (((mask >> i) & 1) == 0) {
                    continue;
                }
                for (char c : arr[i]) {
                    int j = c - 'a';
                    if ((seen >> j) & 1) {
                        flag = true;
                        break;
                    }
                    seen |= (1 << j);
                    len += 1;
                }
                if (flag) {
                    break;
                }
            }
            if (!flag and len > ans) {
                ans = len;
            }
        }
        
        return ans;
    }
};