class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int> min_stack;
        vector<int> ans(n, 0);
        for(int i=0; i<n; i++) {
            while(!min_stack.empty()
                && temperatures[min_stack.top()] < temperatures[i]) {
                ans[min_stack.top()] = i - min_stack.top();
                min_stack.pop();
            }
            min_stack.push(i);
        }
        return ans;
    }
};
