class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int, int> freq;
        
        for (int num : nums) {
            freq[num]++;
        }
        
        int maxFreq = 0;
        int maxElem = 0;
        
        for (auto [num, cnt] : freq) {
            if (maxFreq < cnt) {
                maxFreq = cnt;
                maxElem = num;
            }
        }
        
        const int n = nums.size();
        
        int leftFreq = 0;
        
        for (int i = 0; i < n; ++i) {
            if (nums[i] == maxElem) {
                leftFreq++;
            }
            int rightFreq = maxFreq - leftFreq;
            if (leftFreq*2 > (i + 1) and rightFreq*2 > (n - i - 1)) {
                return i;
            }
        }
        
        return -1;
    }
};