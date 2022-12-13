class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int candidate1, candidate2;
        int vote1 = 0, vote2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                vote1++;
            }
            else if (num == candidate2) {
                vote2++;
            }
            else if (!vote1) {
                candidate1 = num;
                vote1 = 1;
            }
            else if (!vote2) {
                candidate2 = num;
                vote2 = 1;
            }
            else {
                vote1--;
                vote2--;
            }
        }
        vector<int> ans;
        vote1 = vote2 = 0;
        for (int num : nums) {
            if (num == candidate1) {
                vote1++;
            }
            else if (num == candidate2) {
                vote2++;
            }
        }
        int d = n / 3;
        if (vote1 > d) {
            ans.push_back(candidate1);
        }
        if (vote2 > d) {
            ans.push_back(candidate2);
        }
        return ans;
    }
};