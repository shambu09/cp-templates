#include <bits/stdc++.h>
using namespace std;

int count_inv(vector<int> &arr) {
	int n	  = arr.size();
	int count = 0;
	for(int i = 0; i < n - 1; i++) {
		for(int j = i + 1; j < n; j++) {
			if(arr[i] > arr[j]) count++;
		}
	}
	return count;
}

long long C2(int n) { return (n * (n - 1)) / 2; }

const int mod = 1e9 + 7;

long long mpow(long long b, long long ex) {
	if(b == 1) return 1;
	long long r = 1;
	while(ex) {
		if(ex & 1) r = (r * b) % mod;
		ex = ex >> 1;
		b  = (b * b) % mod;
	}
	return r;
}

int solve(int N, vector<int> A) {
	// Write your code here
	if(N == 0) return 1;

	int invs	  = count_inv(A);
	long long ans = pow(15, N);

	ans = (invs * mpow(ans, mod - 2));
	return ans % mod;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	for(int t_i = 0; t_i < T; t_i++) {
		int N;
		cin >> N;
		vector<int> A(6);
		for(int i_A = 0; i_A < 6; i_A++) {
			cin >> A[i_A];
		}

		int out_;
		out_ = solve(N, A);
		cout << out_;
		cout << "\n";
	}
}