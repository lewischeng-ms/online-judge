class Solution {
public:
    vector<vector<int> > subsetsWithDup(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        int cnt = 1 << S.size();
        for (int i = 0; i < cnt; ++i) {
            vector<int> v;
            int k = i;
            vector<int>::iterator j = S.begin();
            while (k > 0) {
                int e = k & 1;
                k >>= 1;
                if (e) v.push_back(*j);
                ++j;
            }
            if (find(result.begin(), result.end(), v) == result.end())
                result.push_back(v);
        }
        return result;
    }	
};