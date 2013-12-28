/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        int low = newInterval.start, high = newInterval.end;
        int i = 0, n = intervals.size();
        while (i < n) { // 遍历所有和newInterval不相交且再它之前的区间
            Interval &itv = intervals[i];
        	if (itv.end >= newInterval.start)
        		break;
        	result.push_back(itv);
        	++i;
        }
        while (i < n) { // 遍历所有和newInterval相交的区间
            Interval &itv = intervals[i];
        	if (itv.start > newInterval.end)
        		break;
        	low = min(low, itv.start);
        	high = max(high, itv.end);
        	++i;
        }
        result.push_back(Interval(low, high));
        while (i < n) { // 遍历所有和newInterval不相交且在它之后的区间
        	Interval &itv = intervals[i];
        	result.push_back(itv);
        	++i;
        }
        return result;
    }
};