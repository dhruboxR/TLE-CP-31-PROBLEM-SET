/*
1875A - Jellyfish and Undertale [ codeforces ] : 900 

*/

#include <bits/stdc++.h>
#define int long long int 
using namespace std ;

void solve() {

    int maxBomb_time, initialBomb_time, number_tools ; 
    cin >> maxBomb_time >> initialBomb_time >> number_tools ; 

    // store the time value of the tools 
    int tool_Box[number_tools] ; 
    for( auto &data : tool_Box) {
        cin >> data ;
    }

    // we will wait for the bomb timer to come to 1 second then we will use the tools 
    int totalTime = initialBomb_time - 1 ; 
    // update the initialBomb_time 
    initialBomb_time = 1 ; 

    // now we will use the toos to increase the bomb timer 
    for(int i=0; i<number_tools; i++) {

        // because of the bug we can get the minimun value of these two 
        initialBomb_time = min( initialBomb_time+tool_Box[i] , maxBomb_time ) ;
        
        // increase the total time till the initial time becomes 1 again 
        totalTime += (initialBomb_time - 1) ;
        // set the initial time to 1 again 
        initialBomb_time = 1 ; 
    }

    // lastly we will have 1 second remaining, we will add that in the total time and print 
    cout << ( totalTime + 1 ) << endl ; 

}

int32_t main() {
    ios_base::sync_with_stdio(false) ; 
    cin.tie(NULL); 

    int test_case;  cin >> test_case;
    while(test_case--) {
        solve() ; 
    }

    return 0 ;
}