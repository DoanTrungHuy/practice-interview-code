class Solution {
public:
    int dfs(int n, int k) {
        cout << n << ' ' << k << '\n';
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
        return !dfs(n - 1, (1 << n) - k);
    }
    
    char findKthBit(int n, int k) {
        return dfs(n, k) + '0';
    }
};