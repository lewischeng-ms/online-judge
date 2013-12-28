#define N_BUCKETS 1000

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> r(2, 0);
        
        int m[N_BUCKETS];
        for (int i = 0; i < N_BUCKETS; ++i)
            m[i] = 0;
        
        for (int i = 1; i <= numbers.size(); ++i) {
            int x = numbers[i - 1];
            
            int y = target - x;
            if (y < 0) continue;
            
            if (!m[x]) m[x] = i;
            
            int j = m[y];
            if (j && j < i) {
                r[0] = j;
                r[1] = i;
                break;
            }
        }
        
        return r;
    }
};