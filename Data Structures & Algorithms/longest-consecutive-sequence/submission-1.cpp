class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> my_max;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for(int i=n-1; i>=0; i--) {
            my_max[nums[i]] = my_max[nums[i]+1] + 1;
        }
        int ans = 0;
        for(auto &cnts: my_max) ans = max(ans, cnts.second);
        return ans;
    }
};
