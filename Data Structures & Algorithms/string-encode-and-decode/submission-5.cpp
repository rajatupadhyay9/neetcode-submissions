class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &str: strs) {
            encoded.push_back((uint8_t)str.size());
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int idx = 0;
        while(idx < s.size()) {
            size_t str_len = (uint8_t)(s[idx++]);
            decoded.push_back(s.substr(idx, str_len));
            idx += str_len;
        }
        return decoded;
    }
};
