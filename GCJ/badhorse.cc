#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	typedef map<string, int> map_type;
	void Read() {
		number_of_pairs = 0;
		cin >> number_of_pairs;
		for (int i = 0; i < number_of_pairs; ++i) {
			string left, right;
			cin >> left >> right;
			problem.push_back(make_pair(left, right));
		}
	}
	void Solve() {
		map_type id;
		bool answer = DFS(0, problem.size(), id);
		if (answer)
			cout << "Yes";
		else
			cout << "No";
	}
	void Finit() {
		problem.clear();
	}
private:
	bool DFS(int dep, int max_dep, map_type &id) {
		if (dep == max_dep)
			return true;
		const string &left = problem[dep].first;
		const string &right = problem[dep].second;
		int id_left = id[left];
		int id_right = id[right];
		if (id_left && id_right) {
			if (id_left == id_right)
				return false;
		} else if (id_left && !id_right) {
			id[right] = 3 - id_left;
		} else if (!id_left && id_right) {
			id[left] = 3 - id_right;
		} else {
			map_type new_id(id);
			new_id[left] = 1;
			new_id[right] = 2;
			if (DFS(dep + 1, max_dep, new_id))
				return true;
			new_id[left] = 2;
			new_id[right] = 1;
			return DFS(dep + 1, max_dep, new_id);
		}
		return DFS(dep + 1, max_dep, id);
	}
	int number_of_pairs;
	vector<pair<string, string> > problem;
};

int main() {
	int number_of_cases = 0;
	cin >> number_of_cases;
	Solution sol;
	for (int i = 1; i <= number_of_cases; ++i) {
		cout << "Case #" << i << ": ";
		sol.Read();
		sol.Solve();
		sol.Finit();
		cout << "\n";
	}
	return 0;
}