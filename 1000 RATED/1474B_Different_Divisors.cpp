#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;
const int mod = 1e9+7;

int square_root(int value) {
    int result = sqrt(value) + 2;
    while (result * result > value) result--;
    return result;
}

int power_cal(int base, int exponent) {
    int result = 1;
    while( exponent ) {
        if( exponent&1 ) {
            result = (result*base) % mod;
        }
        base = (base*base) % mod; 
        exponent >>= 1;
    }
    return result;
}

int next_prime(int value) {
    for(int i=value ;; i++) {
        bool prime = true; 

        for(int j=2; j<=square_root(i); j++) {
            if(i%j == 0) {
                prime = false;  break;
            }
        }
        if( prime ) return i;   // current value is prime
    }
}

void solve() {
    int diff;       cin >> diff;
    // smallest possible integer so start from 1+diff
    int pf_a = next_prime(1+diff);
    int pf_b = next_prime(pf_a+diff);

    int result = min(pf_a*pf_b, pf_a*pf_a*pf_a);
    cout << result << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;     cin >> test_case;
    while (test_case--) {
       solve();
    }

    return 0;
}