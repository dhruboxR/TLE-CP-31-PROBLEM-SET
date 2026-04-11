// LINK - https://codeforces.com/contest/1820/problem/B

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
using namespace std;

const int mod = 1e9+7;

int power_cal(int base, int exponent) {
    int result = 1;
    while (exponent) {
        if (exponent & 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exponent >>= 1;
    }
    return result;
}

void solve() {
    string binary;  cin >> binary; 
    int cnt_one = count( whole(binary), '1');

    if(cnt_one == 0) {cout << 0 << endl;    return;}
    if(cnt_one == 1) {cout << 1 << endl;    return;}
    if(cnt_one == binary.size()) {cout << binary.size()*binary.size() << endl;    return;}

    // maximum consecutive 1
    int cons_one = 0, curr = 0;
    for(int i = 0; i < binary.size(); i++) {
        if(binary[ i ] == '0') {
            cons_one = max(cons_one, curr);     curr = 0;
        } else curr++;
    }
    cons_one = max(cons_one, curr);

    // cyclic shift so front 1's and back 1's are also consecutive 
    int front = 0, back = binary.size() - 1, fbcnt = 0;

    while(front < binary.size() && binary[ front ] == '1') {front++; fbcnt++;} 
    while(back >= 0 && binary[ back ] == '1') {back--;  fbcnt++;}

    cons_one = max(cons_one, fbcnt);

    // Divide cons_one into two parts to maximize their product:
    /*
        MATH FACT:
        For a fixed sum, the product of two integers is maximized when
        the two numbers are as close as possible.

        In code:
            side_one = (cons_one - 1) / 2
            side_two = cons_one - side_one

        So, product = (side_one + 1) * side_two

        Examples:
            cons_one = 4
            side_one = (4-1)/2 = 1, side_two = 3
            Product = (1+1) * 3 = 2 * 3 = 6

            example for 4 : 
            0	1	1	1	1	0
            0	0	1  /1	1	1/  -> area 6
            1	0	0  /1	1	1/
            1	1	0	0	1	1
            1	1	1	0	0	1
            1	1	1	1	0	0


            cons_one = 5
            side_one = (5-1)/2 = 2, side_two = 3
            Product = (2+1) * 3 = 3 * 3 = 9
    */


    int side_one = (cons_one - 1) / 2, side_two = cons_one - side_one;
    cout << (side_one + 1) * side_two << endl;
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
