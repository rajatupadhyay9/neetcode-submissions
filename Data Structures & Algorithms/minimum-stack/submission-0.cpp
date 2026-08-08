class MinStack {
    vector<pair<int, int>> stk;
public:
    MinStack() {
        stk.push_back({INT_MAX, INT_MAX});
    }
    
    void push(int val) {
        stk.push_back({
            val,
            min(val, stk.back().second)
        });
    }
    
    void pop() {
        stk.pop_back();
    }
    
    int top() {
        return stk.back().first;
    }
    
    int getMin() {
        return stk.back().second;
    }
};
