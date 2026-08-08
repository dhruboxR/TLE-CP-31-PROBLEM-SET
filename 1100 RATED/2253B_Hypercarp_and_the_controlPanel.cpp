// https://codeforces.com/contest/2253/problem/B

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

// IMPLEMENTATION SKILL CHECK : INDEX CALCULATION TOOK THE TIME !! 0_0

void solve() {
    int n;  cin >> n; 
    vector<int> arr(n);    int blocks = 1;
    
    // initially how many blocks do we have 
    for(int i = 0; i < n; i++) {
        cin >> arr[ i ]; 
        if(i > 0) {
            if(arr[ i-1 ] != arr[ i ]) ++blocks;
        }
    }
    
    // at max is blocks+2 , blocks+1 is also possible 
    bool one = false, two = false; 
    for(int i = 0; i < n; i++) {
        if(i+3 < n) {
            two |= (arr[ i ] == arr[ i+1 ] && arr[ i+2 ] == arr[ i+3] && arr[ i+1 ] != arr[ i+2 ]);
            one |= (arr[ i ] == arr[ i+1 ] && arr[ i+1 ] != arr[ i+2 ] && arr[ i+1 ] != arr[ i+3 ]); 
        }
        if(i >=3 ) {
            one |= (arr[ i ] == arr[ i-1 ] && arr[ i-1 ] != arr[ i-2 ] && arr[ i-1 ] != arr[ i-3 ]);
        }
    }
    // well front and back check for one 1 2 2 ,,  1 1 2
    if(n >= 3) {
        one |= (arr[ 0 ] != arr[ 1 ] && arr[ 1 ] == arr[ 2 ]);
        one |= (arr[ n-1 ] != arr[ n-2 ] && arr[ n-2 ] == arr[ n-3 ]);
    }
    
    if(two) cout << blocks + 2 << endl; 
    else if(one) cout << blocks + 1 << endl; 
    else cout << blocks << endl;
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