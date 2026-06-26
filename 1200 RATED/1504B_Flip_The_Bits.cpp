// https://codeforces.com/problemset/problem/1504/B
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
    int n;  cin >> n;   string a, b;    cin >> a >> b; 
    if(n == 1) {
        if(a==b) print_yes;
        else print_no;  
        return;
    }
    if(a == b) {print_yes;  return;}

    int balance = 0, match = 0, unmatch = 0, idx = -1;   bool possible = true;
    for(int i = 0; i < n; i++) {
        if(a[ i ] == '0') ++balance;    else --balance;

        if(a[ i ] == b[ i ]) ++match;   else ++unmatch;     // check the prefix 

        // point where cnt0 == cnt1 | can perform operation 
        if( balance == 0 ) {
            idx = i;    // mark the last index 
            // prefix of a == prefix of b [ each idx ]
            // prefix of a != prefix of b [ each idx ]
            if(match > 0 && unmatch > 0) {possible = false;   break;}
            match = 0, unmatch = 0;
        }
    }
    // FINAL CHECK 
    if( !possible ) print_no;
    else {
        // every index after the last index should be equal 
        for(int i = idx+1; i < n; i++) {
            if(a[ i ] != b[ i ]) {possible = false; break;}
        }

        cout << (possible ? "yes" : "no") << endl;
    }
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