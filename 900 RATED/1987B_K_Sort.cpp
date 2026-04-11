/*
1987B - K-SORT [ codeforces ] : 1000 
Given an array of integers a  on length n. You have to make the array NON0-DECREASING 
You can apply the following operations : 
1. Choose an integer k such that 1<=k<=n and PAY k+1 coins k just have to be less than the length of the array 
2. Then choose exactly k indices 
3. Then for each index add +1 to each of them 

Find the minumum number of coins to make the array NON-Decreasing 
*/

#include <bits/stdc++.h>
#define int long long int 
using namespace std ; 

void solve() {
    int length; cin >> length; 
    vector<int> source( length ) ;
    for(auto &data : source ) {
        cin >> data ; 
    }

    int total_values = 0 ;
    map<int, int> difference ; 
    
    for(int i=1; i<length; i++) {

        // if the next value is smaller than previous 
        if( source[i] < source[i-1] ){
            // store the difference in the map 
            difference[ source[i-1] - source[i] ]++ ;
            total_values++ ;    // how many values on which we have to perform the operation 

            // assume that you have performed the operation already so increase the value 
            source[i] = source[i-1] ;   // making the values equal 
        }
    }

    int operation_performed = 0 , coins_required = 0 ; 

    for(auto ite : difference ) {
        coins_required += ( ite.first - operation_performed) * (total_values+1) ;

        operation_performed  = ite.first ; // this many times the operation in done 
        total_values -= ite.second ;
    }

    cout << coins_required << endl ;
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