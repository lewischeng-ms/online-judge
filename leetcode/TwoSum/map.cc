13:26 Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        map<int, int> m;
        vector<int> r;
        for (int i = 1; i <= numbers.size(); ++i) {
            int x = numbers[i - 1];
            int y = target - x;
            
            if (!m[x])
                m[x] = i;
            
            int j = m[y];
            if (j && j < i) {
                r.push_back(j);
                r.push_back(i);
                break;
            }
        }
        
        return r;
    }
};