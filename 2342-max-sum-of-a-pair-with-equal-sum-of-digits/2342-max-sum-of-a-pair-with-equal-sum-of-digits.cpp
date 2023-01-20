class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, int> um;
        int res = -1;
        for (int num : nums) {
            int totalDigit = 0;
            int dummy = num;
            while (dummy > 0) {
                totalDigit += dummy % 10;
                dummy /= 10;
            }
            if (um.count(totalDigit)) {
                res = max(res, um[totalDigit] + num);
            }
            um[totalDigit] = max(um[totalDigit], num);
        }
        return res;
    }
};