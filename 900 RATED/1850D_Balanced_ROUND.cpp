// 1850D - Balanced Round [ codeforces ] : 900 

#include <bits/stdc++.h>
#define int long long int 
using namespace std;

void solve() {
    int num_problems, consecutive_diff; 
    cin >> num_problems >> consecutive_diff ;

    vector<int> rating(num_problems) ; 
    for(auto &data : rating) {
        cin >> data ; 
    }

    sort(rating.begin(), rating.end()) ;

    // search for the maximum cosecutive length 
    int length = 1 , max_length = 1; 

    for(int i=1; i<num_problems; i++) {
        if(rating[i] - rating[i-1] <= consecutive_diff) {
            length++ ;
        } else {
            max_length = max(max_length, length) ;
            length = 1 ;
        }
    }

    // compare one more time for the last comparison
    max_length = max(max_length, length) ;

    cout << (num_problems - max_length) << endl ;

}

int32_t main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) , cout.tie( NULL ) ; 

    int test_case;  cin >> test_case; 
    while(test_case--) {
        solve() ; 
    }

    return 0 ;
}
