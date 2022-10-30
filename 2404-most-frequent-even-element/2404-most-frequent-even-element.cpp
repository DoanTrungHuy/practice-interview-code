class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> mm;
        int maxFreq = 0;
        for (int num : nums) {
            mm[num]++;
            if (num % 2 == 0) {
                maxFreq = max(maxFreq, mm[num]);
            }
        }
        for (auto [val, cnt] : mm) {
            if (val % 2 == 0 and cnt == maxFreq) {
                return val;
            }
        }
        return -1;
    }
};