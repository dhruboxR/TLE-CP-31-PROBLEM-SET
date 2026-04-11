// LINK - https://codeforces.com/problemset/problem/1914/D : Three Activities

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
#define rwhole(vect) (vect).rbegin(), (vect).rend()
#define print_yes (cout << "YES" << endl)
#define print_no (cout << "NO" << endl)
using namespace std;

void solve() {
    int length;     cin >> length; 
    vector<pair<int, int>> skii, cinema, bgame;

    for(int i = 0; i < length; i++) {
        int val;        cin >> val;
        skii.push_back( make_pair(val, i) );
    }
    for(int i = 0; i < length; i++) {
        int val;        cin >> val;
        cinema.push_back( make_pair(val, i) );
    }
    for(int i = 0; i < length; i++) {
        int val;        cin >> val;
        bgame.push_back( make_pair(val, i) );
    }
    // we just need the top 3 maximum from each of the days participants 
    sort( rwhole(skii) );   sort( rwhole(cinema) );    sort( rwhole(bgame) );

    // traverse through all possible combinations and days must be different 
    int mxp = INT_MIN;

    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            for(int k = 0; k < 3; k++) {

                if(skii[ i ].second != cinema[ j ].second && cinema[ j ].second != bgame[ k ].second) {
                    if(skii[ i  ].second != bgame[ k ].second) {
                        int curr = skii[ i ].first + cinema[ j ].first + bgame[ k ].first;
                        mxp = max(curr, mxp);
                    }
                }
            }
        }
    }

    cout << mxp << endl;
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