class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto n: nums) freq[n]++;

        vector<vector<int>> freq_map(nums.size() + 1);
        for(auto &count: freq)
            freq_map[count.second].push_back(count.first);
        
        vector<int> ans;
        for(int i=nums.size(); i>0; i--) {
            if(ans.size() >= k) break;

            for(auto n: freq_map[i])
                ans.push_back(n);
        }
        return ans;
    }
};
