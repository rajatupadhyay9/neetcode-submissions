class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_map<int, bool> nums_hash;
        for(auto n : nums) {
            if(nums_hash[n]) return true;
            nums_hash[n] = true;
        }
        return false;
    }
};