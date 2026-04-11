#include <bits/stdc++.h>
using namespace std ;

void solve() {
    int length;     cin >> length; 
    // declare a vector with length+1 and all elements initialized to zero
    vector<int> elements(length+1, 0) ;
    for(int i=1; i<=length; i++) {
        cin >> elements[i] ;
    }

    int operation_count = 0 ;
    // checking 
    for(int i=1; i<=length; i++) {
        if( elements[i]>0 && elements[i-1]==0) {
            operation_count++ ;
        }
    }
    // our answer won't be greater than 2 ever 
    cout << min(operation_count, 2) << endl ; 
}

int32_t main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ; 

    int test_case;      cin >> test_case; 
    while ( test_case-- ) {
        solve() ; 
    }
    return 0 ;
}