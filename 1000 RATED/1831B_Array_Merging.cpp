#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   //[30 digits]

void calculate_maxSubarray(vector<int> &demoVect, map<int, int> &maxSubarray, int length) {
    
}

void solve() {
    int length;     cin >> length; 
    vector<int>first(length), second(length); 
    
    for(auto &data : first) cin >> data; 
    for(auto &data : second) cin >> data; 

    map<int, int> first_subarray, second_subarray;

    calculate_maxSubarray(first, first_subarray, length);
    calculate_maxSubarray(second, second_subarray, length);
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int test_Case; cin >> test_Case;
    while (test_Case--) {
        solve();
    }

    return 0;
}