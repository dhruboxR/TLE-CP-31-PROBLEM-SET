// LINK - https://codeforces.com/problemset/problem/1840/C
// 1840C - Ski Resort

#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   //[30 digits]

void solve() {
    int days, vacation_days, temp_limit;
    cin >> days >> vacation_days >> temp_limit;

    vector<int> day_temp(days); 
    for(auto &data : day_temp) {
        cin >> data; 
        data = (data<=temp_limit) ? 1:0;
    }

    int count = 0, answer = 0; 
    for(int i=0; i<days; i++) {
        if(day_temp[i]==1) {
            count++;
            if(i==days-1 && count>=vacation_days) {
                int sub = count-vacation_days+1;
                answer+= (sub*(sub+1))/2;
            }
        } else {
            if(count>=vacation_days) {
                int sub = count-vacation_days+1;
                answer+= (sub*(sub+1))/2;
            }
            count = 0;
        }
    }
    cout << answer << endl;
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