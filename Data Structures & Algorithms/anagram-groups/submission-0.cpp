class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<int>> hashes;
        vector<vector<string>> ans;

        for(auto &str : strs) {
            vector<int> cur_hash(26, 0);
            for(auto ch : str) cur_hash[ch-'a']++;
            
            bool found = false;
            for(int i=0; i < hashes.size(); i++) {
                if(hashes[i] == cur_hash) {
                    ans[i].push_back(str);
                    found = true;
                    break;
                }
            }

            if(!found) {
                hashes.push_back(cur_hash);
                ans.push_back({str});
            }
        }

        return ans;
    }
};
