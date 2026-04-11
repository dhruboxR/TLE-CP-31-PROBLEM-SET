/*
2047B - REPLACE CHARACTER : 900 [ codeforces ]

You are given a string s of length n, consisting of only lowercase English Latters. 
You must do the following operation exactly one : 
1. Choose any two indices i and j. You can choose i=j. 
2. Replace a'i with a'j

you need to MINIMIZE THE NUMBER OF DISTINCT PERMUTATIONS OF THE STRING. 
After performing exactly ONE OPERATION.

SOLVE : 
replace the character with minumum frequency with the character of maximum frequency 

*/

#include <bits/stdc++.h>
using namespace std ;

void solve() {
    int length;     cin >> length ; 
    string str;     cin >> str; 

    map<char, int> frequency ;
    for(int i=0; i<length; i++) {
        frequency[ str[i] ]++ ;     // counting the frequency of each character 
    }

    // travarse the map and search the maxfreq and minfreq characters and replace 
    int max_freq = 0 , min_freq = 1000 ;
    char max_temp, min_temp ;       // store the max and min frequency character 
    for(auto ite : frequency) {
        if(ite.second >= max_freq) {
            max_temp = ite.first ;
            max_freq = ite.second ;
        }
        if(ite.second < min_freq) {
            min_temp = ite.first ;
            min_freq = ite.second ;
        }
    }

    // search for the minimum freq character in the string and replace with the max frequency character 
    for(int i=0; i<length; i++) {
        if( str[i] == min_temp ) {
            str[i] = max_temp ;
            break ; 
        }
    }

    cout << str << endl ;
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