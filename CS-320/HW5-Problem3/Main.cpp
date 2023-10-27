#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n = 4; // 4x4 matrix
	vector<vector<int>> x = {
			{1, 2, 3, 4},
			{4, 5, 6, 7},
			{0, 0, 0, 0},
			{8, 9, 1, 2}
	};

	int fAZeroRow = -1;

	for (int i = 0; i < n && fAZeroRow == -1; i++) {
		bool allZ = true;

		for (int j = 0; j < n && allZ; j++) {
			if (x[i][j] != 0) {
				allZ = false;
			}
		}

		if (allZ) {
			fAZeroRow = i;
		}
	}

	if (fAZeroRow != -1) {
		cout << "First all-zero row is: " << fAZeroRow << endl;
	}

	return 0;
}