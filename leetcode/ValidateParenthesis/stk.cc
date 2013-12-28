class Solution {
public:
    static bool match(char a, char b) {
        return a == '(' && b == ')' ||
            a == '[' && b == ']' ||
            a == '{' && b == '}';
    }
    
    bool isValid(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        stack<char> stk;
        for (int i = 0; i < s.size(); ++i) {
            if (stk.empty()) {
                stk.push(s[i]);
            } else {
                char top = stk.top();
                if (match(top, s[i]))
                    stk.pop();
                else
                    stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};