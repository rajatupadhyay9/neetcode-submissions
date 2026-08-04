class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hashes;

        for(auto &str : strs) {
            vector<int> cur_hash(26, 0);
            for(auto ch : str) cur_hash[ch-'a']++;

            string key = "";
            for(auto idx : cur_hash) key += ',' + to_string(idx);
            
            hashes[key].push_back(str);
        }

        vector<vector<string>> ans;
        for(auto &walker : hashes) {
            ans.push_back(walker.second);
        }
        return ans;
    }
};
