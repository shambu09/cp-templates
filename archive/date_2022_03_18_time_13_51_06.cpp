#include <bits/stdc++.h>
using namespace std;
const int nax = 1e6 + 5;
 
int dp[nax][5][3];
int freq[nax];
 
int util(int i, int prev_use, int next_use, int m) {
    int &ret = dp[i][prev_use][next_use];
    if(ret != -1) return ret;
 
    if(i > m) return 0;
 
    if(nax - i < 3)
        return ret =
                   max((freq[i] - prev_use) / 3, (freq[i + 1] - next_use) / 3);
 
    // No consecative triplets
    int case1 = (freq[i] - prev_use) / 3 + util(i + 1, next_use, 0, m);
 
    int min_freq =
        min({freq[i] - prev_use, freq[i + 1] - next_use, freq[i + 2]});
    // One consecative triplets
    int case2 = 0;
    if(min_freq >= 1)
        case2 =
            (freq[i] - prev_use - 1) / 3 + 1 + util(i + 1, next_use + 1, 1, m);
 
    int case3 = 0;
    if(min_freq >= 2)
        case3 =
            (freq[i] - prev_use - 2) / 3 + 2 + util(i + 1, next_use + 2, 2, m);
 
    ret = max({case1, case2, case3});
    return ret;
}
 
void solve() {
    int n, m;
    cin >> n >> m;
 
    int tmp;
    while(n--) {
        cin >> tmp;
        freq[tmp]++;
    }
 
    memset(dp, -1, (m + 1) * 5 * 3 * sizeof(int));
    cout << util(1, 0, 0, m);
}
 
int main() {
    int t = 1;
    // cin >> t;
 
    while(t--) {
        solve();
    }
 
    return 0;
}