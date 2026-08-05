class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        /*
        -1,0,1,2,-1,-4
        -4,-1,-1,0,1,2
        */
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i=0; i<n-2; i++) {
            if(nums[i] > 0) break;
            int l = i+1, r = n-1;
            while(l < r) {
                int sum = nums[l] + nums[r];
                if(sum == -nums[i]) {
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    while(l < n && nums[l] == nums[l-1]) l++;
                } else if(sum < -nums[i]) {
                    l++;
                } else {
                    r--;
                }
            }
            while(i+1 < n && nums[i+1] == nums[i]) i++;
        }
        return res;
    }
};
