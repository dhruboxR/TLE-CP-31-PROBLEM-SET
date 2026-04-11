#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
using namespace std;

// int dx[8] = {-x, -x, x, x, y, y, -y, -y};
// int dy[8] = {y, -y, y, -y, x, -x, x, -x};

const ld pi = 3.141592653589793238462643383279L;
const int mod = 1e9+7;

const int N = 1e7+5;
vector<int> primes;     vector<bool> is_prime(N, true);

void generate_primes() {
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i < N; ++i) {
        if(is_prime[i]) {
            primes.push_back(i);
            for(int j = i * i; j < N; j += i) is_prime[j] = false;
        }
    }
}

int square_root(int value) {
    int result = sqrt(value) + 2;
    while (result * result > value) result--;
    return result;
}

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
    int range;     cin >> range;
    int result = 0; 
    
    for(int i = 1; i <= range; i++) {
        // our current range is i 
        int prime_range = range / i;
        // iterator to count till that range : upperbound stl || binary search - monotonic

        auto in_range = upper_bound(primes.begin(), primes.end(), prime_range);
        int value = in_range - primes.begin();
        result += value;
    }
    cout << result << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    generate_primes();

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}