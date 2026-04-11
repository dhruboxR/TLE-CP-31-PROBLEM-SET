// Link - https://codeforces.com/problemset/problem/1826/B

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
using namespace std;


void solve() {
    int length;     cin >> length; 
    vector<int> source(length+1); 

    int Gdiv = 0;
    for(int i = 1; i <= length; i++) cin >> source[ i ]; 
    for(int i = 1; i <= length; i++) {
        Gdiv = gcd( Gdiv, abs(source[ i ] - source[ length-i+1 ]));
    } cout << Gdiv << endl;
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

    # To solve this problem, we need to find the largest integer x such that:
    # [a1 % x, a2 % x, ..., an % x] becomes a palindrome.

    # Key observation:
        # For the result to be a palindrome, the i-th element from the start must be
        # equal to the i-th element from the end after taking modulo x:
        # That is: a[i] % x == a[n - 1 - i] % x for all i.

    # Rearranging:
        # (a[i] - a[n - 1 - i]) % x == 0
        # This means: x divides (a[i] - a[n - 1 - i])

    # So, x must be a common divisor of all such differences between symmetric elements:
        #   |a[0] - a[n-1]|
        #   |a[1] - a[n-2]|
        #   |a[2] - a[n-3]|, and so on...

    # Now, we want the LARGEST such x that divides all these differences.
    # The largest number that divides a list of numbers is their GCD (Greatest Common Divisor).

    # So the answer is:
    # - If the array is already a palindrome → x can be arbitrarily large → return 0
    # - Otherwise → compute the GCD of all |a[i] - a[n-1-i]| → that’s the maximum x.

*/