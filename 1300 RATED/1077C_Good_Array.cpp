// https://codeforces.com/problemset/problem/1077/C

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
    Given array a1, a2, a3, .... , aN, let's say S = totalSum 
        For element aj, 
        The sum of all other elements except aj must be equal to aj : GoodArray Property
            -> S - aj = aj 
            -> 2aj = S
            -> aj = S / 2

        If any aj is equal to (totalSum/2) in an array then it is a good array 
            - totalSum % 2 == 0 must hold [ for whole integer value ] 
            - totalSum / 2 <= 1e6
            - (totalSum / 2) exists in the array 
*/

void solve() {
    int n;  cin >> n; 
    vector<int> a(n);   map<int, int> freq; 
    int totalSum = 0; 

    for(auto &val : a) {cin >> val; freq[ val ]++;  totalSum += val;}

    vector<int> goodIdx; 
    for(int i = 0; i < n; i++) {
        int newSum = totalSum - a[ i ];
        
        // [ temporary ] : Remove current value and check 
        freq[ a[i] ]--;

        if((newSum % 2 == 0) && (newSum/2 <= 1e6) && (freq[ newSum/2 ] > 0)) {
            goodIdx.push_back( i+1 );
        }
        freq[ a[i] ]++; 
    }
    cout << goodIdx.size() << endl;
    for(auto idx : goodIdx) cout << idx << " "; cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}