// LINK - https://codeforces.com/problemset/problem/1821/B

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
using namespace std;


void solve() {
    int length;     cin >> length; 
    vector<int> first(length), second(length); 

    for(auto &data : first) cin >> data; 
    for(auto &data : second) cin >> data; 

    int left = 0, right = length - 1; 
    for(int i = 0; i < length; i++) {
        if(first[ i ] != second[ i ]) {left = i;    break;}
    }
    for(int i = length - 1; i >= 0; i--) {
        if(first[ i ] != second[ i ]) {right = i;   break;}
    }
    // if we can expand on any sides 
    int l = left, r = right;
    while( l > 0 && second[l-1] <= second[ l ]) l--;
    while( r+1 < length && second[ r+1 ] >= second[ r ]) r++; 

    cout << l + 1 << " " << r + 1 << endl;
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