class Solution {
public:
    int dfs(int n, int k) {
        if (n == 1) {
            return 0;
        }
        int mid = (1 << (n - 1));
        if (k < mid) {
            return dfs(n - 1, k);
        }
        else if (k == mid) {
            return 1;
        }
        return !dfs(n - 1, (mid << 1) - k);
    }
    
    char findKthBit(int n, int k) {
        return dfs(n, k) + '0';
    }
};