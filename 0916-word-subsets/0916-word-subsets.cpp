#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        unordered_map<char, int> words2_freq;
        
        for (const string& word : words2) {
            unordered_map<char, int> temp_freq;
            for (char c : word) {
                temp_freq[c]++;
                words2_freq[c] = max(words2_freq[c], temp_freq[c]);
            }
        }

        vector<string> result;
        
        for (const string& word : words1) {
            unordered_map<char, int> word_freq;
            for (char c : word) {
                word_freq[c]++;
            }

            bool is_universal = true;
            for (const auto& [ch, count] : words2_freq) {
                if (word_freq[ch] < count) {
                    is_universal = false;
                    break;
                }
            }

            if (is_universal) {
                result.push_back(word);
            }
        }
        
        return result;
    }
};
