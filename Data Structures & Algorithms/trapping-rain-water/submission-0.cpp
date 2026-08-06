class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n), right(n);

        int max_till_now = -1;
        for(int i=0; i<n; i++) {
            left[i] = max_till_now;
            max_till_now = max(max_till_now, height[i]);
        }

        max_till_now = -1;
        for(int i=n-1; i>=0; i--) {
            right[i] = max_till_now;
            max_till_now = max(max_till_now, height[i]);
        }

        int ans = 0;
        for(int i=1; i<n-1; i++) {
            int mini = min(left[i], right[i]);
            if(mini > height[i]) ans += mini - height[i];
        }
        return ans;
    }
};
