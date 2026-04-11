/*
1665B - Array Cloning Technique [ codeforces ] 

You are given an array of n integers. Initially there is only one copy of the given array.
You can perform operations of two types :
1. Choose any array and clone it. After that there is one more copy of the choosen array. 
2. Swap two elements from any two copies( maybe in the same copy ) on any positions. 

You need to find the minimal number of operations needed to obtain a copy where all the elements are equal 
*/

#include <bits/stdc++.h>
#define int long long int 
using namespace std ;

void solve() {
    int length; cin >> length;
    int source[ length ] ;

    map<int, int> frequency; 

    for( auto &data : source ) {
        cin >> data ; 
        frequency[ data ]++ ;       // counting the frequency of each element 
    }

    // find the element with the maximum frequency 
    int max_freq = 0 ; 
    for( auto iterator : frequency ) {
        max_freq = max( max_freq, iterator.second ) ;
    }

    int operations = 0 ;
    
    // if the frequency becomes equal than we stop 

    while ( max_freq < length ) {      // while the elements aren't filled up we will continue opertations 
        operations++ ; // cloning is must because without this the max freq element won't be increasing 

        if(length - max_freq >= max_freq) {
            operations += max_freq ;    // swapping 
            max_freq *= 2 ;             // increasing the frequency
        } else {
            operations += (length - max_freq) ;
            max_freq = length ; 
        }
    }  
      
    cout << operations << endl ;
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