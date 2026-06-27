// https://codeforces.com/problemset/problem/1366/B
#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
#define rwhole(vect) (vect).rbegin(), (vect).rend()
#define print_yes (cout << "YES" << endl)
#define print_no (cout << "NO" << endl)
#define print_zero (cout << "0" << endl)
#define negative (cout << "-1" << endl)

        // Initially, the position of 1 is fixed at x, so the reachable range is [x, x].
        
        // For every interval [l, r]:
        //     - If it overlaps with the current reachable range,
        //       expand the reachable range by taking their union.
              
        //     - Otherwise, ignore it since 1 cannot reach that interval.

        // After processing all intervals,
        // every position inside the final reachable range can contain 1.

        // Answer = length of the reachable range = R - L + 1.

void solve() {
    int n, x, m;    cin >> n >> x >> m; 
    int l = x, r = x; 

    for(int i = 0; i < m; i++) {
        int left_bound, right_bound;    cin >> left_bound >> right_bound; 
        if(left_bound > r || right_bound < l) continue; 

        l = min(l, left_bound); 
        r = max(r, right_bound);
    }
    cout << r - l + 1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}