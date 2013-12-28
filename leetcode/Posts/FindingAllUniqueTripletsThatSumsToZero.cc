#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

vector<vector<int> > find_triplets(vector<int> S) {
	vector<vector<int> > triplets;
	if (S.size() < 1) return triplets;
	sort(S.begin(), S.end());
	for (int i = 0; i < S.size(); ++i) {
		if (i > 0 && S[i] == S[i - 1])
			continue;
		int l = i + 1;
		int h = S.size() - 1;
		while (l < h) {
			int sum = S[l] + S[h] + S[i];
			if (sum == 0) {
				vector<int> triplet;
				triplet.push_back(S[i]);
				triplet.push_back(S[l]);
				triplet.push_back(S[h]);
				triplets.push_back(triplet);
				++l;
				--h;
			} else if (sum < 0) {
				++l;
			} else {
				--h;
			}
		}
	}
	return triplets;
}

int main() {
	vector<int> S;
	S.push_back(-1); S.push_back(0); S.push_back(1); S.push_back(2);
	S.push_back(-1); S.push_back(-4);
	vector<vector<int> > triplets = find_triplets(S);
	for (int i = 0; i < triplets.size(); ++i) {
		for (int j = 0; j < triplets[i].size(); ++j)
			cout << triplets[i][j] << " ";
		cout << endl;
	}
	return 0;
}