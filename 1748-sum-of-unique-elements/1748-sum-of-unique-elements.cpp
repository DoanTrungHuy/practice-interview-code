class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int cnt[101] = {};
        for (int num : nums) {
            cnt[num]++;
        }
        int s = 0;
        for (int num : nums) {
            if (cnt[num] == 1) {
                s += num;
            }
        }
        return s;
    }
};