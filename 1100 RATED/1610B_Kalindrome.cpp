// LINK - https://codeforces.com/problemset/problem/1610/B
#include <bits/stdc++.h>
#define int long long int
#define ull unsigned long long
#define ld long double
#define whole(vect) (vect).begin(), (vect).end()
#define print_yes (cout << "YES" << endl)
#define print_no (cout << "NO" << endl)
using namespace std;

// int dx[8] = {-x, -x, x, x, y, y, -y, -y};
// int dy[8] = {y, -y, y, -y, x, -x, x, -x};

const ld pi = 3.141592653589793238462643383279L;
const int mod = 1e9+7;

void solve() {
    int length;     cin >> length; 
    vector<int> source(length);     for(auto &data : source) cin >> data; 

    auto check_palindrome = [&](vector<int>&source, int key) -> bool {
        vector<int> temp;
        
        for(auto &data : source) if(data != key) temp.push_back(data);

        // checking 
        for(int i = 0; i < temp.size(); i++) {
            if(temp[ i ] != temp[ temp.size() - i - 1 ]) return false; 
        }
        return true;
    };

    // finding the first point of difference where source[ i ] != source[ n - i - 1 ]
    bool found = true;      // considering the array is already a palindrome hence a kalindrome as well

    for(int i = 0; i < length; i++) {
        if(source[ i ] != source[ length - i - 1 ]) {
            found = false;
            
            found |= check_palindrome(source, source[ i ]);
            found |= check_palindrome(source, source[ length - i - 1 ]);

            if(found) print_yes;    else print_no;

            return;
        }
    }
    // no difference point found already a palindrome and a kalindrome as well
    print_yes;
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