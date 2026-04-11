// LINK - https://codeforces.com/problemset/problem/1832/B

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
using namespace std;

/*
5 2
0 1 2 3 4
1 2 5 6 10 - sorted 
1 3 8 14 24 - pre sum

we will try out all the possible combinations 
if len = 5 and operation = 2 then, 
2 minimum, 0 maximum 
1 minimum, 1 maximum
0 minimum, 2 maximum
*/

void solve() {
    int length, operation;      cin >> length >> operation; 
    vector<int> source(length);
    for(auto &data : source) cin >> data;
    sort( whole(source) );
 
    vector<int> pre_sum(length);    pre_sum[ 0 ] = source[ 0 ];
    for(int i = 1; i < length; i++) pre_sum[ i ] = pre_sum[ i-1 ] + source[ i ];
 
    int initial = 0;
    for(int first = 0; first <= operation; first++) {
        int second = operation - first; // operation of the second type

        int lidx = first * 2,  ridx = length - second;
        int currs = pre_sum[ ridx-1 ] - (lidx == 0 ? 0 : pre_sum[ lidx-1 ]);
        initial = max(initial, currs);
    } 
    cout << initial << endl;
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