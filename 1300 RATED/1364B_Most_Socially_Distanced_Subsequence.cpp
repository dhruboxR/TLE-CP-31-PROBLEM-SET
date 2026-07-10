// https://codeforces.com/problemset/problem/1364/B

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
    i == 0 or i == n-1 
    a[ i-1 ] < a[ i ] > a[ i+1 ]
    a[ i-1 ] > a[ i ] < a[ i+1 ]
*/

void solve() {
    int length;     cin >> length; 
    vector<int>source(length);      for(auto &val : source) cin >> val; 

    vector<int> subSequence; 
    for(int i = 0; i < length; i++) {
        if(i == 0 || i == length-1) subSequence.push_back( source[ i ] );
        else if(source[ i ] > source[ i-1 ] && source[ i ] > source[ i+1 ])
            subSequence.push_back(source[ i ]); 
        else if(source[ i ] < source[ i-1 ] && source[ i ] < source[ i+1 ])
            subSequence.push_back(source[ i ]); 
    }

    cout << subSequence.size() << endl; 
    for(int v : subSequence) cout << v << " "; cout << endl;
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