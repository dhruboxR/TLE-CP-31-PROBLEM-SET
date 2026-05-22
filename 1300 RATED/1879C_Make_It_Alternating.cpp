// https://codeforces.com/problemset/problem/1879/C
//    COMBINATORICS // PERMUTATION p(a, b) // order matters

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

// factorial pre-calculation
const int mod = 998244353;      vector<int> factVal(200009);

void precalFact() {
    factVal[ 0 ] = factVal[ 1 ] = 1;
    for(int i = 2; i < 200009; i++) factVal[ i ] = (factVal[ i-1 ] * i) % mod;
}

void solve() {
    string check;   cin >> check;   int moveReq = 0, sequenceOp = 1;

    // check for consecutive block of duplicate characters
    for(int i = 1; i < check.size(); i++) {

        // start of a consecutive segment
        if(check[ i ] == check[ i-1 ]) {
            int start = i-1, end = i;
            
            // move the end pointer to the end of this consecutive segment
            while(end + 1 < check.size() && check[ end+1 ] == check[ start ]) end++;

            int segment_length = ( end - start ) + 1;   

            // just one character remains, others are removed [ minimum operation : ∑(segmentLength − 1) ]
            moveReq += segment_length-1;  

                /*  NUMBER OF WAYS TO CHOOSE CHARACTERS THAT STAY AFTER STRING S BECOME ALTERNATING
                    
                    For example, let's consider the string s = 00011. 
                    This string is divided into two blocks 000 and 11
                    
                    So the  number of ways to choose which character stays : len1 * len2 : 3 * 2 = 6
                */

            sequenceOp = (sequenceOp * segment_length) % mod;

            i = end;    // skip the processed segment
        }
    }      
    /*  we have chosen the characters that remain, 
            but we need to choose the characters we erase and the order in which we erase them.

            - If total deletions = d, Then those deletions can happen in any order 
            - Number of orders = d!
    */
    sequenceOp = (sequenceOp * factVal[ moveReq ]) % mod;
    cout << moveReq << " " << sequenceOp << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    precalFact();

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}
