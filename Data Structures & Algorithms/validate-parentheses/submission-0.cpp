class Solution {
    bool check_and_pop_counter(stack<char> &stk, char ch) {
        if(stk.empty() or stk.top() != ch)
            return true;
        stk.pop();
        return false;
    }

public:
    bool isValid(string s) {
        stack<char> paran_track;
        for(auto ch: s) {
            switch(ch) {
                default: break;
                case '(':
                case '{':
                case '[':
                    paran_track.push(ch);
                    break;
                case ')':
                    if(check_and_pop_counter(paran_track, '('))
                        return false;
                    break;
                case '}':
                    if(check_and_pop_counter(paran_track, '{'))
                        return false;
                    break;
                case ']':
                    if(check_and_pop_counter(paran_track, '['))
                        return false;
                    break;
            }
        }
        return paran_track.empty();
    }
};
