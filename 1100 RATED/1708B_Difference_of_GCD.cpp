// LINK - https://codeforces.com/problemset/problem/1708/B 

#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
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

bool powerof_two(int value) {
    if (value <= 0) return false;
    return (value & (value - 1)) == 0;
}

/*
    CEIL DIV  of ( a/b ) 
    ( a + (b-1) ) / b 
*/

/*
    MINIMUM MULTIPLE OF x greater than y

    ceil( y / x) * x;
*/

void solve() {
    int length, l, r;   cin >> length >> l >> r; 

    vector<int> diffgcd; 
    for(int i = 1; i <= length; i++) {
        // min multiple of i [ >= l && < = r ]

        int multiple = ((l + i - 1) / i) * i;       
        
        if(multiple > r) {cout << "NO" << endl; return;}
        diffgcd.push_back(multiple);
    }
    cout << "YES" << endl; 
    for(auto data : diffgcd) cout << data << " ";
    cout << endl;
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