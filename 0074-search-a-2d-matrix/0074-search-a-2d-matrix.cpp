class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size(), col = matrix[0].size();
        int left = 0, right = row*col - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int num = matrix[mid / col][mid % col];
            
            if (num == target) {
                return true;
            }
            else if (num < target) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return false;
    }
};