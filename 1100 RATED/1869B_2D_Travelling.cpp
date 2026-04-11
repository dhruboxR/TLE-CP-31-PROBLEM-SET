#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
using namespace std;

void solve() {
    int cities, major, from, to;    cin >> cities >> major >> from >> to; 
    vector<int> cx(cities+1), cy(cities+1);

    for(int i = 1; i <= cities; i++) {
        cin >> cx[i] >> cy[i];
    }
    int initial = (abs(cx[ from ] - cx[ to ]) + abs(cy[ from ] - cy[ to ]));

    // from to major + to to major
    int from_min = LLONG_MAX / 2, to_min = LLONG_MAX / 2;
    for(int i = 1; i <= major; i++) {
        from_min = min(from_min, abs(cx[ from ] - cx[ i ]) + abs(cy[ from ] - cy[ i ]) );
        to_min = min(to_min, abs(cx[ to ] - cx[ i ]) + abs(cy[ to ] - cy[ i ]) );
    }
    cout << min(initial, from_min + to_min) << endl;
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