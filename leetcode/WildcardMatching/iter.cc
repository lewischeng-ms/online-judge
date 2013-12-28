class Solution {
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        bool star = false; // 是否出现过*
        int i = 0; // 已经匹配的字符个数
        // 基本思想：把s全匹配完，然后看p剩下的是否全都是*。
        // 进一步：先匹配普通字符和？，然后当碰到*时，就在s和p中，把所有已经匹配过的字符砍掉，*也一起砍掉，
        // 但是要在star中标记一下。当发生不匹配情况时，如果star标记过了，那就令之前的那个*一直匹配到s中
        // 这个不能匹配的字符为止。
        while (s[i]) {
            if (p[i] == '?') {
                ++i; // ?和所有字符直接匹配。
            } else if (p[i] == '*') { // p要么在开头，要么在*后面的第一个字符
                star = true;
                p += i; // 把已经匹配成功的前缀砍掉，无需再考虑。
                s += i; // 同上。
                i = 0; // 因为砍掉了前缀，已匹配字符数归零。

                while (*p == '*') ++p; // 多个连续的*和一个*作用是一样的。
                if (!*p) return true; // p已经匹配完毕，它最后一个*可以匹配完s剩下的所有字符，所以匹配成功。
            } else if (s[i] == p[i]) {
                ++i; // 字符相同直接匹配。
            } else { // s[i] != p[i]
                if (!star) return false; // 之前没出现过*，表明匹配失败。
                ++s; // 令之前出现的*直接匹配到s[i]，然后把匹配过的字符全砍掉，p不需要动，因为在碰到p的*时候已经砍过了。
                i = 0; // 砍过了，所以计数器归零。
            }
        }
        // 剩下的p必须全为*。
        while (p[i] == '*') ++i;
        return !p[i];
    }
};