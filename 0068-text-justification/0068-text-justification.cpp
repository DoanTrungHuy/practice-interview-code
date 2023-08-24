class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int i = 0, n = words.size();
        vector<string> line, answ;
        int c = 0;
        
        while (i < n) {
            if (c + line.size() + words[i].size() > maxWidth) {
                string w = "";
                
                if (line.size() > 1) {
                    int extra_spaces = maxWidth - c;
                    int a_space = extra_spaces / (line.size() - 1);
                    int r_space = extra_spaces % (line.size() - 1);
                    for (int j = 0; j < line.size() - 1; ++j) {
                        w += line[j];
                        
                        for (int k = 0; k < a_space; ++k) {
                            w += ' ';
                        }
                        
                        if (r_space > 0) {
                            w += ' ';
                            r_space--;
                        }
                    }
                    
                    w += line.back();
                }
                else {
                    w += line[0];
                    for (int k = 0; k < maxWidth - line[0].size(); ++k) {
                        w += ' ';
                    }
                }
                
                answ.push_back(w);
                c = 0;
                line.clear();
            }
            c += words[i].size();
            line.push_back(words[i]);
            i++;
        }
        
        if (line.size() > 1) {
            string w;
            
            int extra_spaces = maxWidth - c;
            int a_space = extra_spaces / (line.size() - 1);
            int r_space = extra_spaces % (line.size() - 1);
            for (int j = 0; j < line.size() - 1; ++j) {
                w += line[j];

                w += ' ';
            }

            w += line.back();
            int m = w.size();
            
            for (int k = 0; k < maxWidth - m; ++k) {
                w += ' ';
            }
            
            answ.push_back(w);
        }
        else if (line.size() == 1) {
            string w;
            w += line[0];
            for (int k = 0; k < maxWidth - line[0].size(); ++k) {
                w += ' ';
            }
            answ.push_back(w);
        }
        
        return answ;
    }
};