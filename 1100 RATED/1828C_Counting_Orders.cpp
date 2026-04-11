// LINK - https://codeforces.com/contest/1828/problem/C [ DIV-2.C ][ DIV-1.A ]

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

void solve() {
    int length;     cin >> length;
    vector<int> first(length), second(length);
    
    for(auto &data : first) cin >> data;    for(auto &data : second) cin >> data;
    sort(whole( first ));  sort(whole( second ));

    bool no_way = false;            // if any of the second vect's ele is greater than first's
    for(int i = 0; i < length; i++) {
        if( first[ i ] <= second[ i ]) {
            no_way = true;  break;
        }
    } if(no_way) {cout << 0 << endl;    return;}
    /*
        You are given two arrays, a and b, both of length n.
        Your task is to count how many different permutations of array a exist such that:
        
        Count the number of indices i (1 to n) where a[i] > b[i].
        For each position i, count how many elements in a are > b[i].   
        so that, after swapping still every a[i] > b[i]
    */
    int counter = 1;
    for(int i = 0; i < length; i++) {
        int left = i, right = length - 1, index;

        while( left <= right ) {
            int mid = (left + right) / 2;
            if(first[ i ] > second[ mid ]) {
                index = mid;    left = mid + 1;
            } else right = mid - 1;
        }
        int possible_values = (index - i) + 1;
        counter *= possible_values;     counter %= mod;
    }
    cout << counter << endl;
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