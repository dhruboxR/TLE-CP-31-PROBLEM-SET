// https://codeforces.com/problemset/problem/1582/C

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

void solve() {
    int n;  cin >> n;   string pattern; cin >> pattern;
    set<char> alpha;    for(auto &cherr : pattern) alpha.insert(cherr);

    // on every iteraetion we try to skip current character 
    // if id doesn't matthes with the other we skip this cherr

    int chCounter = LLONG_MAX;
    for(auto &c : alpha) {
        int l = 0, r = n-1, counter = 0;
        while( l < r ) {
            if(pattern[ l ] == pattern[ r ]) {++l;  --r;}
            else {
                // got different characters check if one of them is equal to c 
                if(pattern[ l ] == c) {
                    ++l;    ++counter;
                } else if(pattern[ r ] == c) {
                    --r;    ++counter;
                } else {counter = -1; break;}
            }
        }
        if(counter != -1) chCounter = min(chCounter, counter);
    }
    cout << (chCounter == LLONG_MAX ? -1 : chCounter) << endl;
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