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
	if(vec.size() == 0) return os << "[]";
	os << "[";
	for(SIZE_TYPE i = 0; i <= (SIZE_TYPE)vec.size() - 2; i++)
		os << vec[i] << ", ";
	return os << vec.back() << "]";
}

template <class T>
std::ostream& operator<<(std::ostream& os,
						 const std::vector<std::vector<T>>& vec) {
	if(vec.size() == 0) return os << "[]";
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

template <class T, class N>
std::ostream& operator<<(std::ostream& os, const std::pair<T, N> p) {
	return os << "<" << p.first << ", " << p.second << ">";
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

int res;

void dfs(int node,
		 vector<int> &visited,
		 vector<vector<int>> &adj,
		 vector<int> dp,
		 string &values) {

	if(visited[node] == 1 or res == -1) {
		res = -1;
		return;
	}

	res = max(res, dp[values[node - 1] - 'a']);

	if(adj[node].empty()) return;

	for(auto y : adj[node]) {
		dp[values[y - 1] - 'a'] += 1;
		visited[node] = 1;

		dfs(y, visited, adj, dp, values);

		dp[values[y - 1] - 'a'] -= 1;
		visited[node] = 0;
	}
}
int maxPathValue(int n, int m, vector<vector<int>> &edges, string &values) {
	vector<vector<int>> adj(n + 1, vector<int>(0));

	for(auto &edge : edges) {
		adj[edge[0]].push_back(edge[1]);
	}

	vector<int> dp(26, 0);
	vector<int> visited(n + 1, 0);

	res = 0;
	for(int i = 1; i <= n; i++) {
        if(res == -1) return res;
       	
       	fill(dp.begin(), dp.end(), 0);
		adj[0].push_back(i);
		dfs(0, visited, adj, dp, values);
	}

	return res;
}

void solve() {
	int n, m, x, y;
	vector<vector<int>> edges;
	string s;

	cin >> n >> m;
	cin >> s;

	int tmp = m;
	while(tmp--) {
		cin >> x >> y;
		edges.push_back({x, y});
	}

	cout << maxPathValue(n, m, edges, s) << endl;
}

int main() {
	int T;
	cin >> T;

	while(T--) solve();

	return 0;
}