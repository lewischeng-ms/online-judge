#include <vector>
#include <iostream>

using namespace std;

vector<int> findIntersection(vector<int> A, vector<int> B) {
	vector<int> result;
	int i = 0, j = 0;
	while (i < A.size() && j < B.size()) {
		if (A[i] == B[j]) {
			result.push_back(A[i]);
			++i;
			++j;
		} else if (A[i] < B[j]) {
			++i;
		} else {
			++j;
		}
	}
	return result;
}

int main() {
	vector<int> A;
	A.push_back(1);A.push_back(3);A.push_back(5);A.push_back(6);
	vector<int> B;
	B.push_back(2);B.push_back(3);B.push_back(6);
	vector<int> R = findIntersection(A, B);
	for (int i = 0; i < R.size(); ++i)
		cout << R[i] << " ";
	cout << endl;
	return 0;
}