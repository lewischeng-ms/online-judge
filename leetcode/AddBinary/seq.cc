class Solution {
public:
    string addBinaryHelper(string &l, string &s)
    {
        string result(l.size(), 0);
        string::reverse_iterator i = l.rbegin();
        string::reverse_iterator j = s.rbegin();
        string::reverse_iterator k = result.rbegin();
        int c = 0;
        while (i != l.rend()) {
            int d = c + (*i++ - '0');
            if (j != s.rend())
                d += *j++ - '0';
            if (d > 1)
                c = 1, d -= 2;
            else
                c = 0;
            *k++ = d + '0';
        }
        if (c == 1)
            return "1" + result;
        else
            return result;
    }
    
    string addBinary(string a, string b) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (a.size() < b.size())
            return addBinaryHelper(b, a);
        else
            return addBinaryHelper(a, b);
    }
};