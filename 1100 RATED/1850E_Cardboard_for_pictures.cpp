// LINK - https://codeforces.com/problemset/problem/1850/E

#include <bits/stdc++.h>
#define int long long int 
#define ull unsigned long long
#define ld long double
using namespace std;

void solve() {
    int squares, total_area;    cin >> squares >> total_area; 
    vector<int> sides(squares);
    for(int i = 0; i < squares; i++) cin >> sides[i];
    
    // total area for the current width 
    auto in_range = [&](int width) -> bool {
        int curr = 0;
        for(int i = 0 ; i < squares; i++) {
            int val = sides[i] + (2 * width);
            curr += (val * val);
            
            if(curr > total_area) return false;
        } return true;
    };

    int left = 1, right = 1e9, fin_width = 1;
    while( left <= right) {
        int mid = (left + right) / 2;
        if( in_range(mid) ) {
            fin_width = mid;    left = mid + 1;
        } else right = mid - 1;
    }
    cout << fin_width << endl;
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