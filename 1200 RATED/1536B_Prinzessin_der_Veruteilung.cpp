// https://codeforces.com/contest/1536/problem/B

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
        FIND THE MINIMUM POSSIBLE STRING ,
            - That is not present as a substring in the given string

        Check len 1 : a, b, c, ....., z
        Check len 2 : aa, ab, ac, ad, ....., az
        Check len 3 : aaa, aab, aac, aad, ....., aaz, aba, abc, abd, ...., abz, ...., aca, acb, ..., acz

        Checking combination till length 3 is enough [ n <= 1000 ]
*/

void solve() {
    int n;  cin >> n;   string str;     cin >> str; 

    // length 1
    for(char i = 'a'; i <= 'z'; i++) {
        if( str.find(i) == string::npos ) {
            cout << i << endl;  return;
        }
    }
    // length 2 
    for(char i = 'a'; i <= 'z'; i++) {
        for(char j = 'a'; j <= 'z'; j++) {
            string current = "";
            current += i;   current += j;

            if( str.find(current) == string::npos ) {
                cout << current << endl;    return;
            } 
        }
    }
    // length 3 
    for(char i = 'a'; i <= 'z'; ++i) {
        for(char j = 'a'; j <= 'z'; ++j) {
            for(char k = 'a'; k <= 'z'; ++k) {
                string current = ""; 
                current += i;   current += j; current += k;
                
                if( str.find(current) == string::npos ) {
                    cout << current << endl;    return;
                }
            }
        }
    }
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