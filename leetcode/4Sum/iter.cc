class Solution {
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<vector<int> > result;
        sort(num.begin(), num.end());
        int i = 0;
        while (i + 3 < num.size()) {
            int x = num[i];
            threeSum(num, i + 1, target - x, x, result);
            do { ++i; }
            while (i < num.size() && num[i] == x);
        }
        return result;
    }

    void threeSum(vector<int> &num, int start, int target, int first, vector<vector<int> > &result) {
        int i = start;
        while (i + 2 < num.size()) {
            int x = num[i];
            twoSum(num, i + 1, target - x, first, x, result);
            do { ++i; }
            while (i < num.size() && num[i] == x);
        }
    }

    void twoSum(vector<int> &num, int start, int target, int first, int second, vector<vector<int> > &result) {
        int i = start;
        int j = num.size() - 1;
        while (i < j) {
            int sum = num[i] + num[j];
            if (sum == target) {
                vector<int> v;
                v.push_back(first);
                v.push_back(second);
                v.push_back(num[i]);
                v.push_back(num[j]);
                result.push_back(v);
                do { ++i; }
                while (num[i] == num[i - 1]);
                do { --j; }
                while (num[j] == num[j + 1]);
            } else if (sum < target) {
                ++i;
            } else {
                --j;
            }
        }
    }
};