class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length() != t.length()) return false;
        unordered_map<char, size_t> chars_count;
        for(auto ch : s) chars_count[ch]++;
        for(auto ch : t) chars_count[ch]--;

        for(auto char_count : chars_count) {
            if(char_count.second != 0)
                return false;
        }
        return true;
    }
};
