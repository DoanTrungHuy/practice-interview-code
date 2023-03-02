class Solution {
public:
    bool digitCount(string num) {
        unordered_map<char, int> um;
        for (int i = 0; i < num.size(); ++i)
        {
            um[num[i]]++; 
        }
        for (int i = 0; i < num.size(); ++i)
        {
            if (int(num[num[i] - '0'] - '0') != um[num[i]])
            {
                return false;
            }
        }
        return true;
    }
};