#include <bits/stdc++.h>
using namespace std ;

void solve() {

    string binary ;     cin >> binary ; 
    int queries;        cin >> queries ;

    // check if there is any substring equals to 1100 present already 
    int counter = 0 ; 

    for(int i=0; i<binary.size()-3; i++) {

        // substr starts from i and extracts the next 4 characters from i including i 
        if( binary.substr( i,4 ) == "1100")  {
            counter++ ;
        }
    }

    // now check for every query if 1100 is present in the string 
    while ( queries-- ) {
        int index ;     cin >> index ; 
        char value ;    cin >> value ;

        // convert the string to a 0 based index 
        index-- ;  // [ index - 1 ] 

        // check within the 4 possible range of the index if any 1100 substring is present 
        for(int j = index-3; j<=index; j++) {

            // if the value of j becomes negetive(-) or exceeds the range of the string then ignore 
            if( j<0 || j+3>binary.size()) {
                continue ; 
            } else {

                // check if the substring is presnt 
                if(binary.substr(j,4) == "1100") {
                    counter-- ; // because the value is going to be changed 
                }
            }
        }

        // update the index with the value 
        binary[ index ] = value ; 

        // check those 4 possible indices again for the new updated value 
        for(int j=index-3; j<=index; j++) {
            if( j<0 || j+3>binary.size()) {
                continue ;
            } else {
                if(binary.substr(j,4) == "1100") {
                    counter++ ;
                }
            }
        }

        // if the counter value is greater than 0 ( counter > 0 ) 
        if( counter > 0) {
            cout << "YES" << endl ;
        } else {
            cout << "NO" << endl ;
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































// TIME LIMIT EXCEED TLEEEEEE
// BRUTE FORCE APPROACH 

// #include <bits/stdc++.h>
// #define int long long int
// using namespace std ; 

// void solve() {
//     string binary ; cin >> binary ; 
//     int queries;    cin >> queries ; 

//     while( queries-- ) {
//                                         // the index to update 
//         int index ; cin >> index ;
//         char value ; cin >> value ;     // the value to update with 

//         binary[index-1] = value ;
//         bool found = false ;            // check if the sub-string was found 

//         // check for the pattern '1100' only if the string length is sufficient 
//         if(binary.size() > 3) {
//             for(int i=0; i<=binary.size()-3; i++) {

//                 if(binary[i]=='1' && binary[i+1]=='1' && binary[i+2]=='0' && binary[i+3]=='0') {
//                     cout << "YES" << endl ;
//                     found = true ;

//                     break ;
//                 }
//             }
//             if( !found ) cout << "NO" << endl ;
//         } else {
//             cout << "NO" << endl ;
//         }
//     }
// }

// int32_t main() {
//     ios_base::sync_with_stdio( false ) ; 
//     cin.tie( NULL ) , cout.tie( NULL ) ; 

//     int test_case;  cin >> test_case; 
//     while( test_case-- ) {
//         solve() ;
//     }

//     return 0 ;
// }