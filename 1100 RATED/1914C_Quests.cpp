// LINK - https://codeforces.com/contest/1914/problem/C

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;
const int mod = 1e9+7;

const int N = 1e6+5;
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
    int length, move;   cin >> length >> move;
    vector<int> first(length), second(length); 

    for(auto &data : first) cin >> data;
    for(auto &data : second) cin >> data;

    int mx_second = LLONG_MIN, res_xp = 0, tot_first = 0;
    for(int i = 0; i < length && i < move; i++) {
        tot_first += first[i];  
        mx_second = max(mx_second, second[i]);

        int rem_move = move - (i + 1);
        int temp_xp = tot_first + ( rem_move * mx_second);

        res_xp = max(res_xp, temp_xp);
    } cout << res_xp << endl;
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