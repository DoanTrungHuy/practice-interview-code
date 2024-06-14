class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        // sort: 2 cách
        // two pointer
        // binary search
        
        const int n = numbers.size();
        
        for (int i = 0; i < n; ++i) {
            // num1 + num2 = target
            // num1 < num2
            
            int num2 = target - numbers[i];
            
            int l = i + 1;
            int r = n - 1;
            
            while (l <= r) {
                int m = (l + r) / 2;
                
                if (numbers[m] == num2) {
                    return {i + 1, m + 1};
                }
                else if (numbers[m] < num2) {
                    l = m + 1;
                }
                else {
                    r = m - 1;
                }
            }
        }
        
        return {-1, -1};
    }
};