// https://codeforces.com/problemset/problem/1470/A
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

void solve() {
    int n, m;   cin >> n >> m; 
    vector<int> k(n), c(m); 
    for(auto &val : k) cin >> val;  for(auto &val : c) cin >> val;

    sort( rwhole(k) );
    int cost = 0, ptr = 0;

    // Friends with larger k have more expensive default costs.
    // Process them first so they get the cheapest available gifts.
    for(int i = 0; i < n; i++) {
        /*
            Current friend can:
            1. Receive an unused gift j where j <= k[i]
            2. Receive money equal to c[k[i]-1]

            We try to give the cheapest unused gift (ptr)
            if:
            - It is allowed for this friend.
            - It is cheaper than giving money.
        */
        if(ptr < k[ i ] && c[ ptr ] < c[ k[i]-1 ]) {
            cost += c[ ptr ];
            ++ptr;
        } 
        else cost += c[ k[i]-1 ];
    }
    cout << cost << endl;
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