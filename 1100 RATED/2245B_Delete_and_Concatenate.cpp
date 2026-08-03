// https://codeforces.com/contest/2245/problem/B

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
1. Subtract c from every element. Now every operation has zero cost.

2. Let need = ceil(n / 2).

3. Count the number of positive elements (p).
*/

void solve() {
    int n, cost;    cin >> n >> cost; 
    vector<int> values(n);   

    int need = (n + 1) / 2, positive = 0;  // ceil(n / 2)
    for(auto &x : values) {
        cin >> x; x -= cost;
        if(x > 0) ++positive;
    }

    sort( rwhole(values) );     int score = 0;
    for(int i = 0; i < max(need, positive); ++i) {
        score += values[ i ];
    }
    cout << score << endl;
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

/*
Case 1:
--------
    If p >= need,
    keep all positive elements.

    Reason:
        Every positive element increases the answer, and we can always pair
        the unwanted (non-positive) elements among them so that only the
        positive values contribute.

Case 2:
--------
    If p < need,we don't have enough positive elements.

    Even after pairing every negative with a positive (whenever possible),
    we are still forced to let some negative values contribute because
    at least 'need' elements must remain in the final score.

    So we choose the least harmful negatives (the largest non-positive
    values) until we have exactly 'need' contributing elements.

Answer:
--------
    Sort the transformed array in descending order and sum the first

        max(need, p)

    elements.

    Time: O(n log n)
*/