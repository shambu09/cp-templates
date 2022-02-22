#include <bits/stdc++.h>

#include "templates.h"
using namespace std;

const int mod = 1e9 + 7;

class Solution {
  public:
	int maxProfit(vector<int> &A, int T) {
		sort(rall(A));
		int e	= (int)A.size();
		int ans = 0;

		int i	 = 0;
		int left = A[0];

		while(T) {
			while(i < e and A[i] == left) i++;
			int next = i < e ? A[i] : 0;
			int h	 = left - next;

			int cnt = min(T, i * h);
			int r	= 0;

			if(T < i * h) {
				h = T / i;
				r = T % i;
			}

			int val		 = left - h;
			int rect	 = (((0ll + left + val + 1) * h / 2) % mod * i) % mod;
			int rem_rect = (1ll * val * r) % mod;

			ans = (0ll + ans + rect + rem_rect) % mod;
			T -= cnt;
			left = next;
		}
		return (int)ans;
	}
};

int main() {
	int n, t;
	vector<int> arr;

	cin >> n;
	int tmp;

	while(n--) {
		cin >> tmp;
		arr.push_back(tmp);
	}
	
	cin >> t;

	Solution s = Solution();
	cout << s.maxProfit(arr, t);
}
