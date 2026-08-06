class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l = 0, r = heights.size() - 1;
        int ans = 0;
        while(l < r) {
            int left = heights[l], right = heights[r];
            ans = max(ans, (r-l)*min(left,right));

            if(left < right) l++;
            else r--;
        }
        return ans;
    }
};
