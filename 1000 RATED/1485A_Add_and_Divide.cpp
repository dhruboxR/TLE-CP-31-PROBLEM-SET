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

void solve() {
    int value, divisor;     cin >> value >> divisor; 
    int operation_count = 1e18;

    for(int i=0; i<=31; i++) {
        int operation = i, range = value;
        int current_divisor = divisor+i; 

        if(current_divisor == 1) continue;      // skip the infinite loop  
        do {
            range = range / current_divisor;
            operation++;
        } while(range > 0);

        operation_count = min(operation, operation_count);
    }
    cout << operation_count << endl;
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