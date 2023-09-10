class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int diff_x = abs(fx - sx);
        int diff_y = abs(fy - sy);
        
        if (diff_x == 0 and diff_y == 0) {
            return t != 1;
        }
        
        return diff_x <= t and diff_y <= t;
    }
};