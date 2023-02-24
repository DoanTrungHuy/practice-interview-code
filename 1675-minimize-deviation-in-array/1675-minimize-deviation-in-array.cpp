class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size();
        const int oo = 1e9 + 1;
        int minVal = oo;
        for (int i = 0; i < n; ++i) {
            if (nums[i] & 1) {
                nums[i] *= 2;
            }
            minVal = min(minVal, nums[i]);
        }
        int deviation = oo;
        priority_queue<int> pq;
        for (int num : nums) {
            pq.push(num);
        }
        while (pq.top() % 2 == 0) {
            int pTop = pq.top();
            pq.pop();
            deviation = min(deviation, pTop - minVal);
            pTop /= 2;
            minVal = min(minVal, pTop);
            pq.push(pTop);
        }
        return min(deviation, pq.top() - minVal);
    }
};