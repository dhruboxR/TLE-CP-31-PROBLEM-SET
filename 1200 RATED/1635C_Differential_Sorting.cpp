// https://codeforces.com/contest/1635/problem/C

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
    int len;    cin >> len;     vector<int> src(len);   for(auto &val : src) cin >> val; 

    if(is_sorted(whole(src))) {print_zero;  return;}

    if(src.back() < src[ len- 2 ]) {negative;   return;}

    if(src.back() < 0) {negative;   return;}
    
    int dif = src[ len - 2 ] - src.back();
    vector<int> op;

    for(int i = 0; i < len-2; i++) {
        if(src[ i ] > dif || src[ i ] < src[ i-1 ]) {
            src[ i ] = dif;
            op.push_back(i+1);
        }
    }
    cout << op.size() << endl; 
    for(auto v : op) cout << v << " " << len-1 << " " << len << endl;
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