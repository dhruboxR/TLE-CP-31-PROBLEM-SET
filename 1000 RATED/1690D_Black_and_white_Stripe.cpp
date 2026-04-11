#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   // 30 digits

int square_root(int value) {
    int result = sqrt(value) + 2;
    while (result * result > value) result--;
    return result;
}

// SLIDING WINDOW - two pointer [ represents bounds ] - check all the possible cons_len Window 
void solve() {
    int length, cons_len;   cin >> length >> cons_len;
    string stripe;      cin >> stripe;

    int i=0, j=0;   // bounds of the window
    int white_count = 0;   // count of whites in the window

    int min_move = length;  // worst case - all stripes are colored white and we need to change all of them
    while( j<length ) {
        if(stripe[j] == 'W') white_count++;

        // if our window length is less than cons_len then we just increament j 
        if( j-i+1 < cons_len) {
            j++;    continue;
        }
        min_move = min(min_move, white_count);  // update the answer first 

        // then slide the window
        j++;
        if( stripe[i] == 'W') white_count--;    // if the left bound was 'W' 
        i++;
    }
    cout << min_move << endl; 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;     cin >> test_case;
    while (test_case--) {
       solve();
    }

    return 0;
}

/*
    TIME LIMIT EXCEED :) - BRUTEFORCE APPROACH #  

void solve() {
    int length, cons_len;     cin >> length >> cons_len; 
    string stripe;  cin >> stripe;

    int count = LLONG_MAX;

    // if the cons-cell already exists
    string temp (cons_len, 'B');      // consisting of k number of B's

    if(stripe.find(temp) != stripe.npos) {
        cout << 0 << endl; 
    } else {
        for(int i=0; i<=length-cons_len; i++) {
            int len = cons_len, w_count = 0;
            string sub = stripe.substr(i, cons_len);

            for(int j=0; j<len; j++) {
                if(sub[j]=='W') w_count++;
            }
            count = min(count, w_count);
        }
        cout << count << endl; 
    }
}
*/