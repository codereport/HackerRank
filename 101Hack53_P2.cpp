// code_report Solution
// https://youtu.be/6rEp_F7CTH0


#include <vector>
#include <iostream>

using namespace std;

void fillBoard (int n, int m, int x, int y) {

	bool solvable = (n*m - x - y) % 2 == 0; // if tiles to fill not even, can't solve

	if (solvable) {

		vector<int> v;
		vector<vector<int>> res;

		int s = 1; // state
		int c = 0; // count

		vector<vector<int>> li = { { 0, m, 1 },{ m - 1, -1, -1 } }; // loop info for state 0, 1

		for (int i = 0; i < n; i++) {

			if (v.size () == 0 && i != 0) s = ((n - i) % 2 == 0); // set state for special case
			else s = 1 - s; // switch state

			for (int j = li[s][0]; j != li[s][1]; j += li[s][2]) {
				if (c >= x && c < n*m - y) {
					if (j >= m - y && i == n - 1) solvable = false; // run into Y-deleted squares
					v.push_back (i + 1);
					v.push_back (j + 1);
					if (v.size () == 4) {
						res.push_back (v);
						v.clear ();
					}
				}
				c++;
			}
		}

		if (solvable) {
			cout << "YES" << endl << ((n*m - x - y) / 2) << endl;
			for (const auto& v : res) {
				for (const auto& e : v) cout << e << ' ';
				cout << endl;
			}
		}
	}

	if (!solvable) cout << "NO" << endl;
}
