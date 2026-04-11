// LINK - https://codeforces.com/problemset/problem/1715/B
// 1715B - Beautiful Array 

#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   // 30 digits

void solve() {
    int length, div, beauty, sum;   cin >> length >> div >> beauty >> sum;
    // min we can set is (div*beauty) 
    if(div*beauty <= sum) {
        // max we can set in a single position is (div*beauty)+(div-1)
        int val = min(sum, (div*beauty)+(div-1));
        int remaining = sum - val;
        
        // can't distribute the sum 
        if(remaining > (div-1)*(length-1)) {
            cout << -1 << endl;
            return;
        }

        // else we can construct the array 
        vector<int> final_vect(length);
        final_vect[length-1] = val;    sum -= val;

        // travese from the second last index 
        for(int i=length-2; i>=0; i--) {
            if(sum == 0) {
                final_vect[i] = 0;
            }
            else if(sum <= div-1) {
                final_vect[i] = sum;
                sum = 0;
            }
            else if(sum > div-1) {
                final_vect[i] = div-1;     
                sum -= (div-1);
            }
        }

        for(auto &data : final_vect) cout << data << " " ;
        cout << endl;
    } else {
        cout << -1 << endl;
    }
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int test_case; cin >> test_case;
    while (test_case--) {
        solve();
    }

    return 0;
}

