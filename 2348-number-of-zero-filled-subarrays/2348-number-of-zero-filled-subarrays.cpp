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
                ans += cnt * (cnt + 1) / 2; 
                cnt = 0; 
            } 
        } 
        if(nums[n - 1] == 0){ 
            ans += cnt * (cnt + 1) / 2; 
        } 
        return ans; 
    } 
};