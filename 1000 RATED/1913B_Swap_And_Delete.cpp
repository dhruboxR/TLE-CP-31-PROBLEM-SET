// LINK - https://codeforces.com/contest/1913/problem/B
// 1913B : Swap and delete

#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    string word;    cin >> word; 
    int one_count=0, zero_count=0;

    for(int i=0; i<word.size(); i++) {
        if(word[i]=='1') one_count++;
        else if(word[i]=='0') zero_count++;
    }

    // check and swap
    for(int i=0; i<word.size(); i++) {
        if(word[i]=='1') {
            if(zero_count > 0) {
                zero_count--;   
            } else break;
        } else {
            if(one_count > 0) {
                one_count--;
            } else break;
        }
    }
    cout << one_count+zero_count << endl;   // this many elements we were unable to swap so we delete
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL), cout.tie(NULL);

    int test_Case; cin >> test_Case;
    do {
        solve();
        test_Case--;
    } while (test_Case != 0);

    return 0;
}

/*
The idea is we can swap equal number of 1's and 0's present in the string. 
Then the remaining ones we have to delete them - cost per character is 1 coins
*/