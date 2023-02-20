class Solution { 
public: 
    long long zeroFilledSubarray(vector<int>& nums) { 
        long long ans = 0; 
        long long cnt = 0; 
        const int n = nums.size();
        for(int i = 0; i < n; i++){ 
            if(nums[i] == 0) {
                cnt++;
            }
            else{ 
                long long sum = 0; 
                for(long long j = 1;j <= cnt; j++) {
                    sum += j; 
                }
                ans += sum; 
                cnt = 0; 
            } 
        } 
        if(nums[n - 1] == 0){ 
            long long sum = 0; 
            for(long long j = 1; j <= cnt; j++) {
                sum += j; 
            }
            ans += sum; 
        } 
        return ans; 
    } 
};