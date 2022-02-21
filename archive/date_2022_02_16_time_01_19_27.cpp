#include <bits/stdc++.h>
typedef long long ll;
const int nax = 62;

using namespace std;

ll more_bits(int l_set_bits, ll l, ll r, ll k) {
	// l got less bits than desired result so increase l.
	string sl = bitset<nax>(l).to_string();
	ll offset = 0;
	for(int i = nax - 1; i >= 0; i--) {
		if(sl[i] == '0') {
			sl[i] = '1';
			l_set_bits++;
			offset = 1ll << (nax - 1 - i);
			l += offset;
		}
		if(l <= r and l_set_bits == k) return l;
	}

	return -1;
}

ll less_bits(string& sl, int l_set_bits, ll l, ll r, ll k) {
	// l got more bits than desired result so decrease l.
	ll tmp = 0;
	ll offset;
	int co = 0;
	for(int i = nax - 1; i >= 0; i--) {
		if(sl[i] == '1') {
			offset = 1ll << (nax - 1 - i);
			tmp += offset;
			co++;
		}

		if(sl[i] == '0') {
			offset = 1ll << 1 * (nax - 1 - i);

			if((l + offset - tmp) <= r && (l_set_bits - co + 1 == k))
				return (l + offset - tmp);

			if((l + offset - tmp) <= r && (l_set_bits - co + 1 < k)) {
				return more_bits(l_set_bits - co + 1, (l + offset - tmp), r, k);
			}
		}
	}

	return -1;
}

ll solve(ll l, ll r, int k) {
	if(k > 63) return -1;
	string sl	   = bitset<nax>(l).to_string();
	string sr	   = bitset<nax>(r).to_string();
	int msb		   = 0;
	int l_set_bits = 0;

	for(int i = 0; i < nax; i++) {
		if(sl[i] != sr[i]) break;
		if(sl[i] == '1') msb++;
	}

	if(msb > k) {
		return -1;
	}

	for(int i = 0; i < nax; ++i) {
		if(sl[i] == '1') l_set_bits++;
	}

	if(l_set_bits < k) return more_bits(l_set_bits, l, r, k);

	if(l_set_bits == k) return l;

	return less_bits(sl, l_set_bits, l, r, k);
}

int main() {
	int T, k;
	ll l, r;
	cin >> T;

	for(int i = 0; i < T; i++) {
		cin >> l >> r >> k;
		cout << solve(l, r, k) << "\n";
	}
	return 0;
}