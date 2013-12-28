class Solution {
public:
    int candy(vector<int> &ratings) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
        int len = ratings.size();
        vector<int> least(len);
        int count = 0;
        for (int i = 1; i < len; ++i) {
            if (ratings[i] > ratings[i - 1])
                ++count;
            else
                count = 0;
            least[i] = count;
        }
        count = 0;
        for (int i = len - 2; i >= 0; --i) {
            if (ratings[i] > ratings[i + 1])
                ++count;
            else
                count = 0;
            if (count > least[i]) least[i] = count;
        }
        int sum = len;
        for (int i = 0; i < len; ++i)
            sum += least[i];
        return sum;
    }
};