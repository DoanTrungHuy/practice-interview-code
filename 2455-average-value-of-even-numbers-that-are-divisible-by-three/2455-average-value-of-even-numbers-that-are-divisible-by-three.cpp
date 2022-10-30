class Solution {
public:
    int averageValue(vector<int>& nums) {
        int total = 0;
        int cnt = 0;
        for (int num : nums) {
            if (num % 2 == 0 and num % 3 == 0) {
                total += num;
                cnt++;
            }
        }
        if (cnt == 0) {
            return 0;
        }
        return total / cnt;
    }
};