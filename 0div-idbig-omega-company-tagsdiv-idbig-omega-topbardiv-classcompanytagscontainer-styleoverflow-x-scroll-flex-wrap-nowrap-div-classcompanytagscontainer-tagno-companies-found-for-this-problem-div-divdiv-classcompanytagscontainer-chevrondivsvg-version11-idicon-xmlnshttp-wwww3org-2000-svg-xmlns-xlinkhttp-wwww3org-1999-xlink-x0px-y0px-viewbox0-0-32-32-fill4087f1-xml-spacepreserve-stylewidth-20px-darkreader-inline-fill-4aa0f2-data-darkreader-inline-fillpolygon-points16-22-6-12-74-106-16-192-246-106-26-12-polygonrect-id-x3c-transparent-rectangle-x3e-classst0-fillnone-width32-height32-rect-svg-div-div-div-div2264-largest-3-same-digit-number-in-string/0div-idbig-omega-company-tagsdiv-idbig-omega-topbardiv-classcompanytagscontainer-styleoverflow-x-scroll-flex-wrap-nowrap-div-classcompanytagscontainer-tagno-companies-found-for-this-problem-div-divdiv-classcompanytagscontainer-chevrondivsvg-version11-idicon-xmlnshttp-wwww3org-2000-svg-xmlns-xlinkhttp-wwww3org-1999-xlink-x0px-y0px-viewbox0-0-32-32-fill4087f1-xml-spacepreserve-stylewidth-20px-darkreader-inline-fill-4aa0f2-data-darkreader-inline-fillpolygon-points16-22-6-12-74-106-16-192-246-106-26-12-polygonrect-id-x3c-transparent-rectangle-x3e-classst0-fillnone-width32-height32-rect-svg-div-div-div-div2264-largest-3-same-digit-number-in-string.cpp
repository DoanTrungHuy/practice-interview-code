class Solution {
public:
    string largestGoodInteger(string num) {
        int ans = -1;
        int n = num.size();
        
        for (int i = 0; i < n - 2; ++i) {
            if (num[i] == num[i + 1] and num[i] == num[i + 2]) {
                ans = max(ans, num[i] - '0');
            }
        }
        
        return ans != -1 ? string(3, ans + '0') : "";
    }
};