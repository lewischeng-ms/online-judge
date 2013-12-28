class Solution {
public:
    void helper(vector<vector<int> > &result, int _j, int i, int k, vector<int> &num) {
        if (i >= k) {
            result.push_back(v);
        } else {
            for (int j = _j; j < num.size(); ++j) {
                int x = num[j];
                v.push_back(x);
                helper(result, j + 1, i + 1, k, num);
                v.pop_back();
            }
        }
    }
    
    vector<vector<int> > combine(int n, int k) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        vector<int> num(n);
        for (int i = 0; i < n; ++i)
            num[i] = i + 1;
        helper(result, 0, 0, k, num);
        return result;
    }
private:
    vector<int> v;
};