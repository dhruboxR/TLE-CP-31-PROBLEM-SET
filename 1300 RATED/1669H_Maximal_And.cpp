// https://codeforces.com/contest/1669/problem/H

#include <bits/stdc++.h>
using namespace std;

#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
#define rwhole(vect) (vect).rbegin(), (vect).rend()
#define print_yes (cout << "YES" << endl)
#define print_no (cout << "NO" << endl)
#define print_zero (cout << "0" << endl)
#define negative (cout << "-1" << endl)

/*
        The optimal strategy is to take the highest bit such that we have enough
        moves to set that bit in every element
*/

void solve() {
    int length, move;   cin >> length >> move; 
    vector<int> source(length), bitTrack(31, 0);

    for (int i = 0; i < length; i++) {
        cin >> source[ i ];

        // check in which positions the bits are set in this number then update bitTrack 
        for(int j = 30; j >= 0; j--) {
            // in the i'th position we have a set bit
            if(source[ i ] & (1 << j)) ++bitTrack[ j ];
        }
    }

    int finalAnd = 0;
    // QUESTION -> A number can have at most 30 bits 
    for(int i = 30; i >= 0; i--) {
        // how many moves needed to set this bit in every number 
        // totalCount of numbers - how many numbers already have this bit as set bit
        int moveNeeded = length - bitTrack[ i ];
        if( moveNeeded <= move ) {
            move -= moveNeeded;
            finalAnd += ( 1 << i );
        }
    }
    cout << finalAnd << endl; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}