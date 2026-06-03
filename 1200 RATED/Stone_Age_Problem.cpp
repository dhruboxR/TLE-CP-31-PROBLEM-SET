// https://codeforces.com/problemset/problem/1679/B

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
    int len, query; cin >> len >> query;
    vector<pair<int, int>> valQ(len);    int sum = 0;

    for(int i = 0; i < len; i++) {
        int v;  cin >> v;  sum += v;   
        valQ[ i ] = make_pair(v, 0);
    }

    pair<int, int> track = {-1, -1};

    for(int i = 1; i <= query; i++) {
        int type;   cin >> type;
        if(type == 1) {
            int idx, val;   cin >> idx >> val;
            --idx;

            if(valQ[ idx ].second > track.second) {
                // vectorPair has the latest update 
                sum += val - valQ[ idx ].first;
                cout << sum << endl;

                valQ[ idx ].first = val;    valQ[ idx ].second = i;
            } else {
                // track has the latest update
                sum += val - track.first;  cout << sum << endl;
                valQ[ idx ].first = val;    valQ[ idx ].second = i;
            }
        } else {
            int val;    cin >> val;
            track.first = val;  track.second = i;

            sum = val * len;
            cout << val * len << endl;
        }
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}