class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        int l = 0, r = n - 1;
        while(l < r) {
            while(l < n && !isalnum(s[l])) l++;
            while(r >= 0 && !isalnum(s[r])) r--;

            if(l == n || r == 0 || l >= r) return true;
            else if(tolower(s[l]) != tolower(s[r])) return false;
            l++; r--;
        }
        return true;
    }
};
