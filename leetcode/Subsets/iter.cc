class Solution {
public:
    vector<vector<int> > subsets(vector<int> &S) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        // To make the elements of subset sorted.
        sort(S.begin(), S.end());
        vector<vector<int> > result;
        int n = S.size();
        // bool vector to indicate whether
        // each element is selected to be put into subset.
        vector<bool> sel(n);
        bool carry = false;
        while (!carry) { // overflow means all subsets are generated.
            vector<int> subset;
            carry = true; // to plus 1
            for (int i = 0; i < n; ++i) {
                if (sel[i])
                    subset.push_back(S[i]);
                // Do addition.
                bool digit = sel[i] ^ carry;
                carry = sel[i] && carry;
                sel[i] = digit;
            }
            result.push_back(subset);
        }
        return result;
    }
};