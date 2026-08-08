class Solution {
    stack<long> stk;

    template <typename func>
    void operate(func evaluate_logic, int operands) {
        vector<int> args(operands);
        while(operands--) {
            args[operands] = stk.top();
            stk.pop();
        }
        stk.push(evaluate_logic(args));
    }

public:
    int evalRPN(vector<string>& tokens) {
        for(auto token: tokens) {
            if(token == "+")
                operate([](vector<int> &args){ return args[0] + args[1]; }, 2);
            else if(token == "-")
                operate([](vector<int> &args){ return args[0] - args[1]; }, 2);
            else if(token == "*")
                operate([](vector<int> &args){ return args[0] * args[1]; }, 2);
            else if(token == "/")
                operate([](vector<int> &args){ return args[0] / args[1]; }, 2);
            else stk.push(stol(token));
        }
        return stk.top();
    }
};
