/*
in:
5
1 4 3
5 8 4
6 10 6
1 1000000000 1000000000
10 12 8

out:
2
4
5
999999999
5
*/

#include <iostream>
#define ll long long

using namespace std;

void solve() {
	ll l, r, a;
	cin >> l >> r >> a;

	ll x = ((r + 1) / a - 1) * a;
	x += a - 1;
	if(x < l) x = r;

	cout << (x / a) + (x % a) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int t;
	cin >> t;

	while(t--) {
		solve();
	}

	return 0;
}