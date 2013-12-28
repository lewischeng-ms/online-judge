class Solution {
public:
    int canCompleteCircuit(vector<int> &gas, vector<int> &cost) {
        // Note: The Solution object is instantiated only once and is reused by each test case.
    	int start = 0; // 起始站
    	int tank = 0; // 目前车内油量
    	int count = 0; // 访问了几个站？
    	int i = 0; // 目前最远所到达的站
    	// 每次迭代都会恰好访问一个站，访问完所有站即可结束
    	while (count < gas.size()) {
    		int d = gas[i] - cost[i]; // 第i站的油量变化
    		if (tank + d >= 0) { // 足以到达第i+1站就去
    			tank += d;
    			++i;
    		} else { // 不足以到达第i+1站就把起始站往前推移一站。
    			--start;
    			if (start < 0) start += gas.size();
    			tank += gas[start] - cost[start];
    		}
    		++count;
    	}
    	return tank >= 0 ? start : -1;
    }
};