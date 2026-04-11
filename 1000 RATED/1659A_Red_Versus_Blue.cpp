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

/*
length - 13, Red - 10, Blue - 3

Regions Created because of blue : Region = (blue+1) = (3+1) = 4

    ____B____B____B____         : 4 regions created because of 3 blue's

Now we just divide 10 Red's in these 4 regions
1. First (10/4) = 2; Put 2 Red's in each Region 
2. Remaining = (10%4) = 2;  then for the remaining put 1 in each Region
*/

void solve() {
    int length, red, blue;  cin >> length >> red >> blue;

    int regions = blue+1,   region_capacity = (red/regions);
    int remaining = (red%regions);

    if(blue == 1) {
        cout << string(red/2, 'R') << 'B' << string(red - red/2, 'R') << endl; 
        return;
    }
    string final_string = "";
    while(remaining>0) {
        final_string += string(region_capacity+1, 'R') + 'B';
        red -= (region_capacity+1);
        blue--;
        remaining--;
    }
    while(blue>0) {
        final_string += string(region_capacity, 'R') + 'B';
        red -= region_capacity; 
        blue--;
    }
    final_string += string(red, 'R'); 
    cout << final_string << endl; 
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