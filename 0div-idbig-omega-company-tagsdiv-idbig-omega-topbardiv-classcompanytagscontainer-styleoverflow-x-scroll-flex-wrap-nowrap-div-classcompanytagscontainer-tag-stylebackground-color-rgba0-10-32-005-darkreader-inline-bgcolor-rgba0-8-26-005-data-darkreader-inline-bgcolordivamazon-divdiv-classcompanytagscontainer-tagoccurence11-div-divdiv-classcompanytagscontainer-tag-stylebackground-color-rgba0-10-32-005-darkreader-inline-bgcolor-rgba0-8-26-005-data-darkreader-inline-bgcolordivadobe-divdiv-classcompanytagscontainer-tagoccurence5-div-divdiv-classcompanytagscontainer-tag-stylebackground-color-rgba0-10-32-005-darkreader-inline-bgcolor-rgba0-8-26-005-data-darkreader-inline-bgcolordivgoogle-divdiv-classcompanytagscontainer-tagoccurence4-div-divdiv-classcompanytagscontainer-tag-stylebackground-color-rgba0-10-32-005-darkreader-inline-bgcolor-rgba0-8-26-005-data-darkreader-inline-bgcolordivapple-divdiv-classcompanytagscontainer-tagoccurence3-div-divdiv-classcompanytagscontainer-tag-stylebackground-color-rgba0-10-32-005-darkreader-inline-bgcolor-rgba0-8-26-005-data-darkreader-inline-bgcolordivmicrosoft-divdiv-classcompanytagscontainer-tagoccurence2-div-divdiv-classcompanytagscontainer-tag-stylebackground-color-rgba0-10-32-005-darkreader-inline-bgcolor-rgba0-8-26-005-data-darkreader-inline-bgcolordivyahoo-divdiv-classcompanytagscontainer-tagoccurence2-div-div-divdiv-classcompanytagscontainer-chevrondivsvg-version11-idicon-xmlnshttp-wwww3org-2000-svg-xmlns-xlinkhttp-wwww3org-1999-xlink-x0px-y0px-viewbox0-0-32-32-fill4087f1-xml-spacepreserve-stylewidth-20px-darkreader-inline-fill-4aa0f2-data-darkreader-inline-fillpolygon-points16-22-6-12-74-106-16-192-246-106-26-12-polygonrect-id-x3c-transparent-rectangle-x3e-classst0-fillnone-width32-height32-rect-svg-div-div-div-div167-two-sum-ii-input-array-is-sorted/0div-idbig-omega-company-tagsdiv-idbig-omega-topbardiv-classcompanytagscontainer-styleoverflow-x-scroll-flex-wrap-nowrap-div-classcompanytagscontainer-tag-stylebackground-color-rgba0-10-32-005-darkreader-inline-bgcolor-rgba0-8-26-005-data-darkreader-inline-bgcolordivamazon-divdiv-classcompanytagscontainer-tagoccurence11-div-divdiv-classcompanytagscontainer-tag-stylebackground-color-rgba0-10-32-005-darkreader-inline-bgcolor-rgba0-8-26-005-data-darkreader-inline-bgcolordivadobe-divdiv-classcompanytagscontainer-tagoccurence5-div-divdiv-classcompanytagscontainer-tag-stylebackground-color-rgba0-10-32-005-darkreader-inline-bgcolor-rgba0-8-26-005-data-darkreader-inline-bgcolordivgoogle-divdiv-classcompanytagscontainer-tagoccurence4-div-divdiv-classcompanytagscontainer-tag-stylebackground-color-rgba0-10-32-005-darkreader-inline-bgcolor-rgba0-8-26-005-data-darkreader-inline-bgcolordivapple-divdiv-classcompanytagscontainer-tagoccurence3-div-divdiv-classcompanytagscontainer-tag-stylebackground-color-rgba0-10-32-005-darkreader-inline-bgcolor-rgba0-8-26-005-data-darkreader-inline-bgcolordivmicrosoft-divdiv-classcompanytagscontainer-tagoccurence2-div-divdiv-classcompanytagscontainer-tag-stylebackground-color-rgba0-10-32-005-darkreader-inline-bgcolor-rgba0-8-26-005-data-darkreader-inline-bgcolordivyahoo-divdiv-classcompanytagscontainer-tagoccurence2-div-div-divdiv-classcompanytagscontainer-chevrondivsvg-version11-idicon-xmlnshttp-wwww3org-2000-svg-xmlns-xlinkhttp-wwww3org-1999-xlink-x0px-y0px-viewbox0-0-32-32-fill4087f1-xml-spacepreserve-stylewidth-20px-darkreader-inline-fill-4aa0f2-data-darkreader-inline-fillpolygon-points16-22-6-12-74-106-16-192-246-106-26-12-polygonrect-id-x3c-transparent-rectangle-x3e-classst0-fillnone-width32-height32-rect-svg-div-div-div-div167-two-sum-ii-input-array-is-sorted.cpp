class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // sort: 2 cách
        // two pointer
        // binary search
        
        int left = 0;
        int right = numbers.size() - 1;
        
        while (left <= right) {
            int val = numbers[left] + numbers[right];
            if (val == target) {
                return {left + 1, right + 1};
            }
            else if (val < target) {
                left++;
            }
            else {
                right--;
            }
        }
        
        return {-1, -1};
    }
};