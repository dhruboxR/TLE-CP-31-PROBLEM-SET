// LINK - https://codeforces.com/contest/2061/problem/B
// 2061b - Kevin and Geometry [ Isosceles Trapezoid ]

#include <bits/stdc++.h>
#define int long long int
#define ld long double
using namespace std;

const ld pi = 3.141592653589793238462643383279L;   // 30 digits

void solve() {
    int len;    cin >> len;
    vector<int> sticks(len);    map<int, int> stick_freq;
    for(auto &data : sticks) {
        cin >> data;    stick_freq[ data ]++;
    }

    vector<int> pair;
    for(auto freq:stick_freq) {
        if(freq.second>=4) {
            cout << freq.first << " " << freq.first << " " << freq.first << " " << freq.first << endl;
            return;
        }
        if(freq.second >= 2) {
           pair.push_back(freq.first);
        }
    }
    if(pair.size()==0) {
        cout << -1 << endl;     // no valid pairs to form trapezoid
        return;
    } else {
        // double pair
        if(pair.size()>=2) {
            cout << pair[0] << " " << pair[0] << " " << pair[1] << " " << pair[1] << endl;
        }
        else if(pair.size()==1) {
            // find the pair
            if(stick_freq.find(pair[0]) != stick_freq.end()) {
                if(stick_freq[pair[0]] > 2) {
                    stick_freq[pair[0]] -= 2;
                } else {
                    stick_freq.erase(pair[0]);  // else we erase the value 
                }
            }

            bool found = false ;
            vector<int> temp;
            for(auto data : stick_freq) temp.push_back(data.first);
            for(int i=0; i+1<temp.size(); i++) {
                if(abs(temp[i+1]-temp[i])< 2*pair[0]) {
                    cout << pair[0] << " " << pair[0] << " " << temp[i] << " " << temp[i+1] << endl;
                    found = true;
                    return;
                }
            }
            if(!found) cout << -1 << endl;
        }
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