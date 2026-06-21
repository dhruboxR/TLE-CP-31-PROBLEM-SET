// https://codeforces.com/problemset/problem/2208/B

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
    int n, k, p, m; cin >> n >> k >> p >> m;
    --p;    --k;    // 0 based 

    vector<int> src(n);     for(auto &val : src) cin >> val;

    int ans = 0, sum = 0, dist = p, ace = src[ p ];
    
    // Till the energy burns out 
    while(sum <= m)  {
        
        if(dist <= k) {
            sum += ace;
            if(sum <= m) ans++;

            auto reorder = src; reorder.push_back(ace);  // Putting the Ace in the back of the deck
            // remove the first Ace that we just used initially at distance p [ dist = p ]
            reorder.erase(reorder.begin() + dist);

            // update the source & distance  
            src = reorder;
            dist = n-1;     
        }
        else {
            // Choose the minimum element from the first k elements 
            int mn = LLONG_MAX, idx = 0; 
            for(int i = 0; i <= k; i++) {
                if(src[ i ] < mn) {
                    mn = src[ i ];  idx = i;
                }
            }
            sum += mn;

            auto reorder = src; reorder.push_back(mn);
            reorder.erase(reorder.begin() + idx);

            src = reorder;
            --dist;     // the win card moves closer
        }
    }

    cout << ans << endl;
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