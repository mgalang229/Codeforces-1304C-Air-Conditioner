#include <bits/stdc++.h>
using namespace std;

/*

rules:
1. if cur_lb <= prev_lb <= cur_ub and prev_ub >= cur_ub, then [prev_lb, cur_ub]
2. if cur_lb <= prev_lb <= cur_ub and cur_lb <= prev_ub < cur_ub, then [prev_lb, prev_ub]

3. if prev_lb < cur_lb and cur_lb <= prev_ub <= cur_ub, then [cur_lb, prev_ub]
4. if prev_lb < cur_lb and prev_ub > cur_ub, then [cur_lb, cur_ub]

otherwise, it's impossible to satisfy all the customers

*/

struct Range {
	int lb, ub;
};

void test_case(int& tc) {
	int n, m;
	cin >> n >> m;
	int t[n], l[n], h[n];
	for (int i = 0; i < n; i++)
		cin >> t[i] >> l[i] >> h[i];
	int prev_time = 0;
	Range prev, cur;
	prev.lb = m;
	prev.ub = m;
	bool possible = true;
	for (int i = 0; i < n; i++) {
		int diff = t[i] - prev_time;
		prev.lb -= diff;
		prev.ub += diff;
		cur.lb = l[i];
		cur.ub = h[i];
		if (cur.lb <= prev.lb && prev.lb <= cur.ub && prev.ub >= cur.ub) {
			prev.ub = cur.ub;
		} else if (cur.lb <= prev.lb && prev.lb <= cur.ub && cur.lb <= prev.ub && prev.ub <= cur.ub) {
			// do nothing (retain original values)
		} else if (prev.lb < cur.lb && cur.lb <= prev.ub && prev.ub <= cur.ub) {
			prev.lb = cur.lb;
		} else if (prev.lb < cur.ub && prev.ub > cur.ub) {
			prev.lb = cur.lb;
			prev.ub = cur.ub;
		} else {
			possible = false;
			break;
		}
		prev_time = t[i];
	}
	cout << (possible ? "YES": "NO") << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int T = 1;
	cin >> T;
	for (int tc = 1; tc <= T; tc++)
		test_case(tc);
}
