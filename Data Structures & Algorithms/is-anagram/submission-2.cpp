#define BYTE_MAX_VALS 256

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;

        vector<int> ch_counts(sizeof(char) * BYTE_MAX_VALS, 0);
        for(int i=0; i<s.length(); i++) {
            ch_counts[s[i]]++;
            ch_counts[t[i]]--;
        }

        for(int ch_count : ch_counts) {
            if(ch_count != 0) 
                return false;
        }
        
        return true;
    }
};
