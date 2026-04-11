/*
1666D - Deletive Editing [ codeforces ] 

Given an initial and final string, check if it is possible to achive the final string from the initial string 
You can a character from the initial string in order to get the final string 
But you have to delete the first occurance of the character 

Print Yes if possible else NO 
*/

#include <bits/stdc++.h>
using namespace std ;

void solve() {
    string initial, final;
    cin >> initial >> final ;

    // count the frequencies for each character in both of the strings 
    map<char, int> initial_counter, target_counter ;

    for(auto character : initial) {     // initial string frequencies
        initial_counter[ character ]++ ;
    }
    for(auto character : final) {       // final string frequencies
        target_counter[ character ]++ ;
    }

    // declare TWO POINTER to iterate through the strings 
    int initial_pointer = 0, target_pointer = 0 ;
    
    while ( initial_pointer<initial.size() && target_pointer<final.size()) {
        // check if the characters matches 
        if(initial[ initial_pointer ] == final[ target_pointer ]) {
            // if the initial frequency is less than the target frequency 
            if( initial_counter[ initial[initial_pointer] ] < target_counter[ final[target_pointer] ]) {
                break ;  
            }

            if( initial_counter[ initial[initial_pointer] ] == target_counter[ final[target_pointer] ]) {
                target_counter[ final[target_pointer] ]-- ;
                target_pointer++ ;
            }
        }
        // we will decrease the count in the initial string anyway cause we are checking
        initial_counter[ initial[initial_pointer] ]-- ;
        initial_pointer++ ;
    }

    // if the target pointer value is equal to the length of the final string 
    if( target_pointer == final.size()) {
        cout << "YES" << endl ; 
    } else {
        cout << "NO" << endl ; 
    }

}

int main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ; 

    int test_case;  cin >> test_case; 
    while ( test_case-- ) {
        solve() ;
    }

    return 0 ;
}