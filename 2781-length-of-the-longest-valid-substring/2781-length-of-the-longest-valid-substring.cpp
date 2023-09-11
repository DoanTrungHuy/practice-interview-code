struct TrieNode {
    TrieNode *child[26];
    bool isWord;
    
    TrieNode() {
        for (int i = 0; i < 26; ++i) {
            child[i] = nullptr;
        }
        isWord = false;
    }
};

struct Trie {
    TrieNode *root;
    
    Trie() {
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode *curr = this->root;
        for (char c : word) {
            if (curr->child[c - 'a'] == nullptr) {
                curr->child[c - 'a'] = new TrieNode();
            }
            curr = curr->child[c - 'a'];
        }
        curr->isWord = true;
    }
    
    bool search(int l, int r, string &word) {
        TrieNode *curr = this->root;
        for (int i = l; i <= r; ++i) {
            char c = word[i];
            if (curr->child[c - 'a'] == nullptr) {
                return false;
            }
            if (curr->child[c - 'a']->isWord) {
                return true;
            }
            curr = curr->child[c - 'a'];
        }
        return curr->isWord;
    }
};

class Solution {
public:
    int longestValidSubstring(string word, vector<string>& forbidden) {
        Trie t;
        
        for (string bidden : forbidden) {
            t.insert(bidden);
        }
        
        const int n = word.size();
        int ans = 0;
        
        for (int i = n - 1, j = n - 1; i >= 0; --i) {
            while (i <= j and t.search(i, j, word)) {
                j--;
            }
            ans = max(ans, j - i + 1);
        }
        
        return ans;
    }
};