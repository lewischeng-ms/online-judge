// 基本思路：不能或尚未匹配的左右括号都要进栈。
// 栈顶top表示最近尚未匹配的括号位置，如果刚在栈顶发生了成功匹配（并把匹配的左括号弹出），
// 那么现在的top+1就是该次成功匹配的开始位置。
class Solution {
public:
    int longestValidParentheses(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (s.empty()) return 0;
        
        stack<int> stk;
        int i = 0;
        int result = 0;
        while (i < s.size()) {
            if (s[i] == '(') { // 左括号直接进栈
                stk.push(i);
            } else { // 是右括号
                if (!stk.empty() && s[stk.top()] == '(') { // 栈顶是左括号
                    stk.pop(); // 弹出左括号，配对
                    int len;
                    if (stk.empty()) // 栈为空表示从s开头到i都成功匹配，所以长度是i+1
                        len = i + 1;
                    else // 否则栈顶括号的位置是i之前的还没匹配的，即本次匹配的范围是：top+1到i，长度是i-(top+1)+1=i-top
                        len = i - stk.top();
                    if (len > result) result = len;
                } else { // 栈为空或栈顶为右括号的话直接进栈
                    stk.push(i);
                }
            }
            ++i;
        }
        return result;
    }
};
