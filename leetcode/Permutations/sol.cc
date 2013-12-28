class Solution {
public:
    void helper(vector<vector<int> > &result, vector<int> &num) {
        if (num.empty()) {
            result.push_back(v);
        } else {
            int i = 0;
            while (i < num.size()) {
                int x = num[i];
                v.push_back(x);
                num.erase(num.begin() + i);
                helper(result, num);
                v.pop_back();
                num.insert(num.begin() + i, x);
                ++i;
            }
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        helper(result, num);
        return result;
    }
private:
    vector<int> v;
};