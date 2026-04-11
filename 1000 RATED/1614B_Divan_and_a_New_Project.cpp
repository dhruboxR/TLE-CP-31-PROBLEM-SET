// LINk - https://codeforces.com/problemset/problem/1614/B
// 1614B - Divan and a New Project

#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   // 30 digits

int square_root(int value) {
    int result = sqrt(value) + 2;
    while (result * result > value) result--;
    return result;
}

void solve() {
    int length;     cin >> length; 
    vector<pair<int, int>> visit_freq(length); 

    for(int i=0; i<length; i++) {
        cin >> visit_freq[i].first; 
        visit_freq[i].second = i+1;       // corresponding 1 based index of the building
    }
    // sort will be based on the first value 
    sort(visit_freq.rbegin(), visit_freq.rend());

    int headquarter = 0,    curr_distance = 1,  total_time = 0; 
    vector<int> final_answer(length+1); 
    final_answer[0] = headquarter;

    for(int i=0; i<length; i++) {
        int index = visit_freq[i].second,   freq = visit_freq[i].first;

        total_time += 2*curr_distance*freq;
        if( (i+1)&1 ) {
            final_answer[ index ] = curr_distance; 
        } else {
            final_answer[ index ] = 0 - curr_distance;
            // 2 times initialization done 
            curr_distance++;
        }
    }

    cout << total_time << endl; 
    for(auto data : final_answer) cout << data << " ";
    cout << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int test_case;     cin >> test_case;
    while (test_case--) {
       solve();
    }

    return 0;
}