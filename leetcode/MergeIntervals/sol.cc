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
	struct Comparer {
		bool operator()(const Interval &x, const Interval &y) const {
			return x.start < y.start;
		}
	};

    vector<Interval> merge(vector<Interval> &intervals) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        vector<Interval> result;
        int n = intervals.size();
        if (n < 1) return result;
        sort(intervals.begin(), intervals.end(), Comparer());
        Interval last = intervals[0];
        for (int i = 1; i < n; ++i) {
        	Interval &itv = intervals[i];
        	if (itv.start > last.end) {
        		result.push_back(last);
        		last = itv;
        	} else {
        		last.start = min(last.start, itv.start);
        		last.end = max(last.end, itv.end);
        	}
        }
       	result.push_back(last);
        return result;
    }
};