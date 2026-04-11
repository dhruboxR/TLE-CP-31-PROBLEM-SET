#include <bits/stdc++.h>
#define int long long int
using namespace std ;

void solve() {
    int length, queries;    cin >> length >> queries; 

    int source[length] ; 
    // elements of the main array 
    for(auto &data : source) {
        cin >> data ; 
    } 

    // prefix sum 
    int prefix_sum[length+1] ;  prefix_sum[0] = 0 ;
    for(int i=1; i<=length; i++) {
        prefix_sum[i] = prefix_sum[ i-1 ] + source[ i-1 ] ;
    }

    while ( queries-- ) {
        int start , end, value ;   
        cin >> start >> end >> value ;

        // Convert to Zero based indexing 
        start-- ; end-- ;

        // Original Sum in the range 
        int range_sum = prefix_sum[end+1] - prefix_sum[start] ;

        // calculate the new sum and check 
        int new_sum = (end-start + 1) * value ; 
        int new_total = prefix_sum[ length ] - range_sum + new_sum ;
        
        if(new_total % 2 == 0) {
            cout << "NO" << endl ;
        } else {
            cout << "YES" << endl ;
        }
    }

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
