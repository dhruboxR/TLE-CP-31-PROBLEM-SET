// https://codeforces.com/problemset/problem/1881/D

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

const int N = 1e6+5;
vector<int> primes;     vector<bool> markPrime(N, true);

void generatePrimes() {
    markPrime[ 0 ] = markPrime[ 1 ] = false;
    for(int i = 2; i < N; ++i) {
        if( markPrime[ i ] ) {

            primes.push_back( i );
            for(int j = i*i; j < N; j += i) markPrime[ j ] = false;
        }
    }
}

void solve() {
    int length;     cin >> length;  
    map<int, int> primeFreq;

    for(int i = 0; i < length; i++) {
        int value;  cin >> value; 

        for(auto div : primes) {
            if(div*div > value) break;          // no need to check prime divisors ahead   

            while( value % div == 0 ) {
                value /= div;   primeFreq[ div ]++;
            }
        }
        if(value > 1) primeFreq[ value ]++;
    }
    // equal division of the divisors
    for(auto [key, frequency] : primeFreq) {
        if( frequency % length ) {print_no;     return;}
    }
    print_yes;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    generatePrimes();

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}