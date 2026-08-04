#include <cstring>
class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &str: strs) {
            char str_size[2]; // uint16_t max len supported 64K
            uint16_t str_len = str.size();
            memcpy(str_size, &str_len, sizeof(uint16_t));
            encoded.append(str_size, sizeof(uint16_t));
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int idx = 0;
        while(idx < s.size()) {
            uint16_t str_len = 0;
            memcpy(&str_len, &s[idx], sizeof(uint16_t));
            idx += sizeof(uint16_t);
            decoded.push_back(s.substr(idx, str_len));
            idx += str_len;
        }
        return decoded;
    }
};
