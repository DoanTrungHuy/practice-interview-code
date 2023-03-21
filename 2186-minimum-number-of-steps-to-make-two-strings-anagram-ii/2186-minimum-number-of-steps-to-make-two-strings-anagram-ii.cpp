class Solution
{
public:
    int minSteps(string s, string t)
    {
        int um1[26] = {};
        int um2[26] = {};
        for (char c : s)
        {
            um1[c - 'a']++;
        }
        for (char c : t)
        {
            um2[c - 'a']++;
        }
        int count = 0;
        for (int i = 0; i < 26; i++)
        {
            count += abs(um1[i] - um2[i]);
        }
        return count;
    }
};