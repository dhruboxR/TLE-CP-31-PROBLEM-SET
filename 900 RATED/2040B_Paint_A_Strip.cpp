/*
2040B : PAINT A STRIP : 900 [ codeforces ] 

Given an array consisting of only zeros of length n ;
You can perform two types of operation on it 
1. Choose an index i such that 1<=i<=n and a'i = 0 then assign 1 to a'i .
2. Choose any pair of indices l and r such that 1<=l<=r<=n and l = 1 and r = 1,
   and assign 1 to all the elements to 1 .

What is the minimum number of first type operation needed to make all the elements of the array 
Equal to 1.
*/

#include <bits/stdc++.h>
using namespace std ;

void solve() {
    int range;  cin >> range; 

    int operation_count = 2 ;   // we already performed two operations for length 4
    
    if(range == 1) {
        cout << 1 << endl ;
        return ;
    } else if(range<=4 && range>1) {
        cout << 2 << endl ;
        return ;
    } else {
        int sum = 4 ;

        while(sum < range) {
            sum++ ;  // place the last 1 and then multiply
            sum *= 2 ;
            operation_count++ ;
        }
    }

    cout << operation_count << endl ;
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