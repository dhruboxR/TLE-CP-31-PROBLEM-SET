// LINK - https://codeforces.com/problemset/problem/1857/C : Assembly Via Minimums

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
using namespace std;

void solve() {
    int length;     cin >> length; 
    int slen = (length * (length - 1)) / 2;

    vector<int> second(slen);   for(auto &data : second) cin >> data;   
    sort( whole(second) );

    // the min ele wil appear length - 1 times, second min will appear n-2 times .........
    int idx = 0;
    for(int count = length - 1; count >= 1; count--) {
        cout << second[ idx ] << " ";
        idx += count;
    }
    // the largest element form the first array won't appear so 1 element remains to print
    cout << *max_element( whole(second) ) << endl;
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