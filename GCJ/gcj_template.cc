#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Solution {
public:
	void Read() {

	}
	void Solve() {

	}
	void Finit() {

	}
private:
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