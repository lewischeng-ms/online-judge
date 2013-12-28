struct Item {
    int v;
    int i;
    
    bool operator<(const Item &x) const {
        return v < x.v;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<int> res(2, 0);
        
        vector<Item> v(numbers.size());
        for (int i = 0; i < numbers.size(); ++i) {
            v[i].v = numbers[i];
            v[i].i = i + 1;
        }
        
        sort(v.begin(), v.end());
        
        int l = 0, r = v.size() - 1;
        while (l < r) {
            int sum = v[l].v + v[r].v;
            if (sum == target) {
                res[0] = v[l].i;
                res[1] = v[r].i;
                if (res[1] < res[0])
                    swap(res[0], res[1]);
                break;
            } else if (sum < target) {
                ++l;
            } else {
                --r;
            }
        }
        
        return res;
    }
};