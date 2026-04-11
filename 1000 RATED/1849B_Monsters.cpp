// LINK - https://codeforces.com/problemset/problem/1849/B
//1849B : MONSTERS

#include <bits/stdc++.h>
#define int long long int
using namespace std;

void solve() {
    int length, damage;     cin >> length >> damage; 
    vector<int> monsters(length);
    vector<pair<int, int>> final_indices;

    for(int i=0; i<length; i++) {
        cin >> monsters[i]; 

        if(monsters[i]%damage == 0) {
            final_indices.push_back(make_pair(damage, (i+1)*-1));
            continue;
        }
        final_indices.push_back(make_pair(monsters[i]%damage, (i+1)*-1));  
    }

    sort(final_indices.rbegin(), final_indices.rend());     // ascending order
    for(auto data : final_indices) {
        cout << data.second*-1 << " ";
    } cout << endl;
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
The monsters with health equal to the damage dies first 
then we store the rest of the values as (value % damage) and their index[ 1 based ];
now becasue of (value % damage) every remaining of the monsters will be dead with a single blow. 
-starting in ascending order 
[ how does the sort function works in c++, fist value then second value] 
-sort them in the ascending order and the corredponding indices is our final answer.
*/
