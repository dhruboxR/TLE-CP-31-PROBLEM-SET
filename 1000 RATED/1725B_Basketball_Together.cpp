#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   // 30 digits

void solve() {
    int players, opponent_power;    cin >> players >> opponent_power;
    
    vector<int> power(players);
    for(auto &data:power) cin >> data; 
    sort(power.rbegin(), power.rend());     // descending order 

    int taken = 0, win_count = 0; 
    for(auto data : power) {
        // how many of this level player needed
        int player_need = ceil(((double)opponent_power+1)/data);
        
        if(taken+player_need > players) break;
        else {
            win_count++;
            taken += player_need;
        }
    }
    cout << win_count << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    solve();

    return 0;
}