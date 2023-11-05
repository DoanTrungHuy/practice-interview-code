class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int win_count = 0;
        int max_ele = arr[0];
        
        for (int i = 1; i < (int)arr.size(); ++i) {
            if (arr[i] > max_ele) {
                max_ele = arr[i];
                win_count = 0;
            }
            if (++win_count == k) {
                return max_ele;
            }
        }
        
        return max_ele;
    }
};