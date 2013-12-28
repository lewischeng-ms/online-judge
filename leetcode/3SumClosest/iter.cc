class Solution {
public:
	int gsum;
	int gdiff;

    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        if (num.size() < 3) return 0;
        sort(num.begin(), num.end());
        int i = 0;
        gsum = num[0] + num[1] + num[2];
        gdiff = abs(gsum - target);
        while (i + 2 < num.size()) {
            int x = num[i];

        	twoSumClosest(num, i + 1, x, target);
        	if (gsum == target) return target;

        	do { ++i; }
        	while (i < num.size() && num[i] == x);
        }
        return gsum;
    }

    void twoSumClosest(vector<int> &num, int start, int first, int target) {
    	int i = start;
    	int j = num.size() - 1;
    	while (i < j) { // 每次努力向靠近target的方向改进，因此不会遗漏最优解
    		int sum = first + num[i] + num[j];
    		if (sum == target) {
    			gsum = target;
    			gdiff = 0;
    			return;
    		}

    		if (sum < target)
    			++i;
    		else
    			--j;

    		int diff = abs(sum - target);
    		if (diff < gdiff) {
    			gdiff = diff;
    			gsum = sum;
    		}
    	}
    }
};