class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        queue<int> mq;
        
        for (int i = 1; i <= 9; ++i) {
            mq.push(i);
        }
        
        vector<int> ans;
        
        while (!mq.empty()) {
            int num = mq.front();
            mq.pop();
            
            if (low <= num and num <= high) {
                ans.push_back(num);
            }
            
            if (num > high) {
                break;
            }
            
            if (num%10 < 9) {
                mq.push(num*10 + (num%10) + 1);
            }
        }
        
        return ans;
    }
};