// the maximum gcd of a,b is always abs(a-b)

#include <bits/stdc++.h>
#define int long long int 
using namespace std ; 

void solve() {
    int a, b;   cin >> a >> b;

    if(a<b) {
        swap(a, b) ;
    }

    if(a==b) {
        cout << 0 << " " << 0 << endl ;
        return ;
    } 

    int operation = min(b%(a-b), (a-b)-( b%(a-b) )) ;
    cout << abs(a-b) << " " << operation << endl ;
}

int32_t main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ; 

    int test_case;  cin >> test_case;
    while( test_case-- ) {
        solve() ; 
    }

    return 0 ;
}