class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        
        int pos_val = 1;
        
        arr[0] = 1;
        
        for (int i = 0; i < (int)arr.size(); ++i) {
            if (pos_val == arr[i]) {
                
            }
            else {
                arr[i] = ++pos_val;
            }
        }
        
        return pos_val;
    }
};