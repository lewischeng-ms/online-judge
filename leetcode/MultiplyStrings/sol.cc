class Solution {
public:
    void multiplyTo(const string &x, char y, string &result) {
        int a = y - '0';
        int c = 0; // carrier
        for (int i = 0; i < x.size(); ++i) {
            int b = x[i] - '0';
            int d = a * b + c;
            c = d / 10;
            d %= 10;
            char e = '0' + d;
            result += e;
        }
        if (c > 0) {
            char e = '0' + c;
            result += e;
        }
    }
    
    void addTo(const string &x, string &result) {
        int c = 0;
        int i;
        for (i = 0; i < x.size(); ++i) {
            int a = x[i] - '0';
            int b = result[i] - '0';
            int d = a + b + c;
            c = d / 10;
            d %= 10;
            result[i] = d + '0';
        }
        if (c > 0) result[i] = '1';
    }
    
    string multiply(string num1, string num2) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int t = 0;
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());
        string result(num1.size() + num2.size(), '0');
        for (int i = 0; i < num2.size(); ++i, ++t) {
            char x = num2[i];
            if (x =='0') continue;
            string mult(t, '0');
            multiplyTo(num1, x, mult);
            addTo(mult, result);
        }
        // 去掉高位多余的0
        int c = 0;
        int j = result.size() - 1;
        while (result[j] == '0') {
            --j;
            ++c;
        }
        result.resize(result.size() - c);
        reverse(result.begin(), result.end());
        return result.empty() ? "0" : result;
    }
};