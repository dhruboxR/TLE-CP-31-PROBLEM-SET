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
    string first, second;   cin >> first >> second;
    int flen = first.size(), slen = second.size();

    if(first == second) {
        cout << 0 << endl;      return;
    }

    //  we apply BRUTEFORCE cause we still don't know DP :( 
    vector<string>generated_substrings; 
    string initial = first;

    for(int ini_len = 1;ini_len<=initial.size(); ini_len++) {

        for(int j=0; j<=initial.size()-ini_len; j++) {
            generated_substrings.push_back(initial.substr(j, ini_len));
        }
    }

    // search from longest to smallest
    string search_str = second; 
    bool found = false ;    int max_comlen = 1;

    for(int i=generated_substrings.size()-1; i>=0; i--) {
        string curr_sub = generated_substrings[i];

        if(search_str.find(curr_sub) != string::npos) {
            found = true;
            max_comlen = curr_sub.size();
            // cout << "curr_sub : "<< curr_sub << " : " << curr_sub.size() << endl;
            break;
        }
    }

    if(found) {
        cout << (flen + slen) - (2 * max_comlen) << endl;
    } else cout << flen+slen << endl;   // empty strings will always match 
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;  cin >> test_case; 
    while(test_case--) {
        solve();
    }

    return 0;
}