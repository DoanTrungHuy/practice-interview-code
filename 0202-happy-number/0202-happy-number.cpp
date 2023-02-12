class Solution {
public:
    int splitDigit(int n) {
        int s = 0;
        while (n > 0) {
            int t = n % 10;
            s += t * t;
            n /= 10;
        }
        return s;
    }
    bool isHappy(int n) {
        int slow = n, fast = n;
        do {
            slow = splitDigit(slow);
            fast = splitDigit(fast);
            fast = splitDigit(fast);
        } while (slow != fast);
        return fast == 1;
    }
};