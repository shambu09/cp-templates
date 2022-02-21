#include <bits/stdc++.h>


#ifndef SIZE_TYPE
#define SIZE_TYPE int
#endif

#ifndef STORAGE_TYPE
#define STORAGE_TYPE int
#endif
//--------------- Printing a std::vector and std::array | tags - printing, vector, print----------------//

template <class T>
std::ostream& operator<<(std::ostream& os, const std::vector<T>& vec) {
	os << "[";
	for(SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ", ";
	return os << vec.back() << "]";
}

template <class T>
std::ostream& operator<<(std::ostream& os,
						 const std::vector<std::vector<T>>& vec) {
	os << "[ " << vec[0] << ",\n";
	for(SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

template <class T, std::size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T, N>& vec) {
	os << "[";
	for(SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ", ";
	return os << vec.back() << "]";
}

template <class T, std::size_t N, std::size_t M>
std::ostream& operator<<(std::ostream& os,
						 const std::array<std::array<T, N>, M>& vec) {
	os << "[ " << vec[0] << ",\n";
	for(SIZE_TYPE i = 1; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << "  " << vec[i] << ",\n";
	return os << "  " << vec.back() << " ]";
}

//----------------------------------------------------------------------------------------//

//----------------------shortcut for vector.begin() and vector.end()----------------------//
#ifndef all
#define all(s) s.begin(), s.end()
#endif

#ifndef rall
#define rall(s) s.rbegin(), s.rend()
#endif
//----------------------------------------------------------------------------------------//

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
