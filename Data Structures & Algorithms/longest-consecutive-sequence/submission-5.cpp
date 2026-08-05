class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        /*
         1 2 3 10 11 12
        */
        int ans = 0;
        unordered_map<int, bool> freq;
        for(auto n: nums) freq[n] = true;

        for(auto n: nums) {
            if(!freq.contains(n)) continue;

            if(!freq.contains(n-1)) {
                int len = 0;
                while(freq.contains(n)) {
                    // freq.erase(n);
                    len++;
                    n++;
                }
                ans = max(ans, len);
            }
        }

        return ans;

        // int n = nums.size();
        // set<int> seto;
        // for(auto n: nums) seto.insert(n);
        // for(auto n: seto) {
        //     my_max[n] = my_max[n-1] + 1;
        // }
        // int ans = 0;
        // for(auto &cnts: my_max) ans = max(ans, cnts.second);
        // return ans;
    }
};
