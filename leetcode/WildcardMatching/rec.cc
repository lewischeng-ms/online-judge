static char q[33000];
static bool x[33000][33000];
class Solution {
public:
    bool isMatch(const char *s, const char *p) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = strlen(s);
        int n = strlen(p);
        n = 0;
        while (*p) {
            if (*p == '*') {
                q[n++] = *p++;
                while (*p == '*')
                    ++p;
            } else {
                q[n++] = *p++;
            }
        }
        p = q;
        x[0][0] = true;
        for (int i = 1; i <= m; ++i)
            x[i][0] = false;
        x[0][1] = p[0] == '*';
        for (int j = 2; j <= n; ++j)
            x[0][j] = p[j - 1] == '*' && x[0][j - 1];
        for (int i = 1; i <= m; ++i) {
            for (int j = 1; j <= n; ++j) {
                if (p[j - 1] == '?')
                    x[i][j] = x[i - 1][j - 1];
                else if (p[j - 1] == '*') {
                    x[i][j] = x[i][j - 1];
                    for (int k = 0; k <= i && !x[i][j]; ++k)
                        x[i][j] = x[i][j] || x[k][j - 1];
                } else if (p[j - 1] == s[i - 1]) {
                    x[i][j] = x[i - 1][j - 1];
                } else {
                    x[i][j] = false;
                }
            }
        }
        return x[m][n];
    }
};