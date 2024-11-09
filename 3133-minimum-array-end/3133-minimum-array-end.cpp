class Solution {
public:
    long long minEnd(int n, int x) {
        long long t = x;
        
        while (--n) {
            t = (t + 1) | x;
        }
        
        return t;
    }
};