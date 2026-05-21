// https://codeforces.com/contest/1669/problem/D

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
    int length;     cin >> length; 
    string strip;   cin >> strip;

    bool red = false, blue = false;
    for(int i = 0; i < length; i++) {
        red |= strip[ i ] == 'R';
        blue |= strip[ i ] == 'B';

        if( strip[ i ] == 'W' ) {
            if((!red && !blue) || (red && blue)) {
                red = false;    blue = false;
                continue;
            } 
            else {print_no; return;}
        }
    }
    if( (!red && !blue) || (red && blue) ) print_yes;   else print_no;
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
