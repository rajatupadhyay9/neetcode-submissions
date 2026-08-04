class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size(), cur_prod;
        vector<int> result(n, 1);

        cur_prod = 1;
        for(int i=1; i<n; i++) {
            cur_prod *= nums[i-1];
            result[i] = cur_prod;
        }

        cur_prod = 1;
        for(int i=n-2; i>=0; i--) {
            cur_prod *= nums[i+1];
            result[i] *= cur_prod;
        }
        return result;
    }
};
