class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int, int> my_max;
        int n = nums.size();
        set<int> seto;
        for(auto n: nums) seto.insert(n);
        for(auto n: seto) {
            my_max[n] = my_max[n-1] + 1;
        }
        int ans = 0;
        for(auto &cnts: my_max) ans = max(ans, cnts.second);
        return ans;
    }
};
