/*
1675B - Make It Increasing [ codeforces ]

Given an array of n integers. You can perform the following operation on them
* Select any element of the array and divide it by 2( round down ) in other words you can select an element 
  a'i and replace it with the value of a'i/2

OUTPUT the minimum number of operations to make the array strictly increasing 
if not possible then print -1 
*/

#include <bits/stdc++.h>
#define int long long int
using namespace std ;

void solve() {
    int length;     cin >> length; 
    int source[ length ] ; 
    for(auto &data : source) {
        cin >> data ;
    }

    int move_count = 0 ;

    for(int i=length-2; i>=0; i--) {
        if(source[i+1] == 0) {
            cout << -1 << endl ;
            return ;
        }
        // if current value is greater or equal than the front value and the front value is greater than 0
        while ( source[i]>=source[i+1] && source[i+1] > 0) {
            source[i] /= 2 ;
            move_count++ ;
        }
    }
    cout << move_count << endl ;
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