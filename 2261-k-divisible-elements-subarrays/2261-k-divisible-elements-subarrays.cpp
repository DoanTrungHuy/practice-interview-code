class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unordered_set<string> us;
        for (int i = 0; i < nums.size(); ++i)
        {
            int c = 0;
            string tmp;
            for (int  j = i; j < nums.size(); ++j)
            {
                if (nums[j] % p == 0)
                {
                    c++;
                }
                if (c > k)
                {
                    break;
                }
                tmp += nums[j] + '0';
                us.insert(tmp);
            }
        }
        return us.size();
    }
};