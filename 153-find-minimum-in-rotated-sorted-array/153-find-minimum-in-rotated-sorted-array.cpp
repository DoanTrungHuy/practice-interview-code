class Solution {
public:
    int findMin(vector<int>& nums) {
        int minNum = INT_MAX;
        for (int num : nums) {
            minNum = min(minNum, num);
        }
        return minNum;
    }
};