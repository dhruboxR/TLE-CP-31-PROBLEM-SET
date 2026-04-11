#include <bits/stdc++.h>
#define int long long int 
using namespace std ; 

void solve() {
    int a , b , c ;     cin >> a >> b >> c ; 

    // condition for a 
    int result_a = (2*b - c) % a ;  // 2b-c have to be greater than 0 
    // condition for b 
    int result_b = ((a+c)/2) % b ; // (a+c) have to be divisible by 2
    // condition for c 
    int result_c = (2*b - a) % c ; // 2b-a must be greater than 0 

    if(result_a==0 && (2*b-c)>0) {
        cout << "YES" << endl ;
    } else if(result_b==0 && (a+c)%2==0) {
        cout << "YES" << endl ;
    } else if(result_c==0 && (2*b-a)>0) {
        cout << "YES" << endl ;
    } else {
        cout << "NO" << endl ;
    }
}

int32_t main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ;

    int test_case;  cin >> test_case;
    while ( test_case-- ) {
        solve() ;
    }

    return 0 ;
}