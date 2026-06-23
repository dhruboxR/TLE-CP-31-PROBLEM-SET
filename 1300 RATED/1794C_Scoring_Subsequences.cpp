// https://codeforces.com/contest/1794/problem/C

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

/* 
    we are finding the index till which it contributes to the score 
    every time we append an element x, the score is multiplied by [ x / d+1 ] * rest 
*/

void solve() {
    int n;  cin >> n;   vector<int> source(n);  for(auto &val : source) cin >> val; 
    int l = 0; 

    for(int i = 0; i < n; i++) {
        // The longest suffix ending at i whose smallest element is at least its length
        while(source[ l ] < i-l+1) l++;
        cout << (i - l + 1) << " ";
    }
    cout << endl;
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