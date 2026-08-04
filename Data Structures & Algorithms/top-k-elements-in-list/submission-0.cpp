class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        for(auto n: nums) freq[n]++;

        vector<pair<int, int>> freq_array;
        for(auto &count: freq) {
            freq_array.push_back({count.second, count.first});
        }

        sort(freq_array.rbegin(), freq_array.rend());

        vector<int> result(k);
        for(int i=0; i<k; i++) result[i] = freq_array[i].second;
        return result;
    }
};
