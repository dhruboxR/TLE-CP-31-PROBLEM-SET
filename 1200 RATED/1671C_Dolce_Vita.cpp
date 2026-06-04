// https://codeforces.com/problemset/problem/1671/C

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
    int len, cash;  cin >> len >> cash; int sum = 0; 
    vector<int> price(len), prefix(len);    
    
    for(auto &val : price) cin >> val;
    sort( whole(price) );

    for(int i = 0; i < len; i++) {prefix[ i ] = (i == 0 ? price[ i ] : prefix[ i-1 ] + price[ i ]);}
    int sugarcane = 0;

    // For how many days i will be able to buy that sugar packet 
    for(int i = 0; i < len; i++) {
        int high = 1e9, low = 1, best = 0;

        while( low <= high ) {
            int mid = (high + low) / 2;

            int cost = prefix[ i ] + (i+1) * (mid - 1);
            if(cost <= cash) {
                best = mid;
                low = mid + 1;
            } else high = mid - 1;
        }

        sugarcane += best;
    }
    cout << sugarcane << endl;
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