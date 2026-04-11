/*
 1837B - COMPARISON STRING [ codeforces ] : 900

 Construct an array according to the given comparison string and determine the 
 minimum number of unique elements with which we can costruct the array
*/

#include <bits/stdc++.h>
using namespace std ;

void solve() {

    int length_s ;       cin >> length_s ; 
    string comparison ;  cin >> comparison ; 

    // DETERMINE THE LONGEST CONSECUTIVE CHARACTERS WITH SAME SIGN 
    int minimum_cost = 0 , consecutive_count = 0 ; 

    for(int i=0; i<length_s; i++) {
        consecutive_count++ ;
        // we will stop our count if it is the last element or if the consecutive character does not matches 
        if( i == length_s-1 || comparison[i] != comparison[i+1] ) {
            minimum_cost = max(consecutive_count, minimum_cost) ;
            consecutive_count = 0 ; 
        }
    }

    cout << minimum_cost + 1 << endl ;

}

int main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ;

    int test_case;  cin >> test_case; 
    while( test_case-- ) {
        solve() ; 
    }

    return 0 ; 
}