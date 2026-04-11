// LINk - https://codeforces.com/problemset/problem/1744/C

// 1744C - Traffic Lights

#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   //[30 digits]

void solve() {
    int length;     cin >> length;
    char current;   cin >> current; 

    map<char, set<int>> char_index;
    for(int i=0; i<length; i++) {
        char character;     cin >> character;
        
        char_index[ character ].insert(i+1); // inserting 1-based index  
    }
    if(current =='g') {     // we can cross immidiately
        cout << 0 << endl;  return;
    }

    int max_distance = 0;    // iterate through the indices of the current element 
    for(auto index : char_index[current]) {
        // the nearest 'g' after this index
        auto it_green = char_index['g'].lower_bound(index);

        int distance;
        if(it_green != char_index['g'].end()) {
            // direct distance cause the iterator didn't reached the end 
            distance = *it_green - index;
        } else {
            // circular distance 
            distance = (length-index) + *char_index['g'].begin();   // the pointer of the begining element in the g-indices
        }

        max_distance = max(distance, max_distance);
    }
    cout << "# -> " << max_distance << endl;
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