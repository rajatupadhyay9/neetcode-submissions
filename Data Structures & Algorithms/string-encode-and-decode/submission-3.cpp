class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded = "";
        for(auto &str: strs) {
            encoded.push_back('R');
            uint8_t str_len = str.size();
            // cout<<"strlen = #"<<str.size();
            encoded.back() = str_len;
            encoded += str;
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string> decoded;
        int idx = 0;
        while(idx < s.size()) {
            size_t str_len = static_cast<uint8_t>(s[idx]);
            idx++;
            decoded.push_back(s.substr(idx, str_len));
            idx += str_len;
        }
        return decoded;
    }
};
