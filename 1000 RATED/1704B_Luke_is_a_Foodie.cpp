#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   // 30 digits

void solve() {
    int len, max_diff;  cin >> len >> max_diff;
    vector<int> pile(len); 
    for(auto &data : pile) cin >> data;

    int change_count = 0, minimum = pile[0], maximum = pile[0];
    for(int i=0; i<len; i++) {
        minimum = min(minimum, pile[i]);
        maximum = max(maximum, pile[i]);

        if(maximum-max_diff > minimum+max_diff) {
            change_count++; 
            minimum = pile[i];
            maximum = pile[i];
        }
    }
    cout << change_count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}