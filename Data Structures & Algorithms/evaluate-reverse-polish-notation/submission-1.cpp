class Solution {
    stack<long> stk;

    template <typename func>
    void binary_evaluate(func evaluate_logic) {
        long b = stk.top();
        stk.pop();
        long a = stk.top();
        stk.pop();
        stk.push(evaluate_logic(a, b));
    }

public:
    int evalRPN(vector<string>& tokens) {
        for(auto token: tokens) {
            if(token == "+")
                binary_evaluate([](int a, int b){ return a + b; });
            else if(token == "-")
                binary_evaluate([](int a, int b){ return a - b; });
            else if(token == "*")
                binary_evaluate([](int a, int b){ return a * b; });
            else if(token == "/")
                binary_evaluate([](int a, int b){ return a / b; });
            else stk.push(stol(token));
        }
        return stk.top();
    }
};
