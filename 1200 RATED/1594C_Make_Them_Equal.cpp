// https://codeforces.com/problemset/problem/1594/C

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
    int n; cin >> n;    char cherr; cin >> cherr;
    string str;     cin >> str;

    if(str == string(n, cherr)) {print_zero;  return;}

    // if all of the multiples are cherr 
    for(int div = 2; div <= n; ++div) {
        bool valid = true; 

        for(int pos = div; pos <= n; pos += div) {
            if( str[ pos-1 ] != cherr ) {
                valid = false;  break;
            }
        }

        if( valid ) {
            cout << 1 << endl; cout << div << endl; return;
        }
    }
    cout << 2 << endl; 
    cout << n << " " << n-1 << endl;
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