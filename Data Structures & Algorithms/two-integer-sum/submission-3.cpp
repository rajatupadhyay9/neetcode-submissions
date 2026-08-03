class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> nums_hash;

        for(int idx = 0; auto n : nums) {
            if(nums_hash.count(target-n) > 0)
                return {nums_hash[target-n], idx};
            nums_hash[n] = idx;
            idx++;
        }
        return {};
    }
};
