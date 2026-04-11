#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
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
    int initial_val, desired_val; 
    cin >> initial_val >> desired_val; 

    if(initial_val > desired_val) swap(initial_val, desired_val);
    int operation = 0; 
    while(initial_val <= desired_val) {
        // we check in the descending order, helps to reach value faster 
        if(initial_val * 8 <= desired_val) {
            initial_val *= 8;   operation++;
        } else if(initial_val * 4 <= desired_val) {
            initial_val *= 4;   operation++;
        } else if(initial_val * 2 <= desired_val) {
            initial_val *= 2;   operation++;
        } else break;   
    }
    if(initial_val == desired_val) cout << operation << endl;
    else cout << -1 << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int test_case;     cin >> test_case;
    while (test_case--) {
       solve();
    }

    return 0;
}