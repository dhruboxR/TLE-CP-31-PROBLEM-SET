// LINK - https://codeforces.com/problemset/problem/1620/B
// 1620B - Triangles on a Reactangle

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

int determine_base(vector<int> vect) {
    int base = *max_element(vect.begin(), vect.end()) - *min_element(vect.begin(), vect.end());
    return base;
}

void solve() {
    int height_a, height_b;     cin >> height_a >> height_b;
    vector<int> x_up, x_down, y_up, y_down;

    for(int i=0; i<4; i++) {
        int pot;    cin >> pot;
        if(i==0) {
            for(int i=0; i<pot; i++) {
                int val;    cin >> val;
                x_up.push_back(val);
            }
        }
        else if(i==1) {
            for(int i=0; i<pot; i++) {
                int val;    cin >> val; 
                x_down.push_back(val);
            }
        } else if(i==2) {
            for(int i=0; i<pot; i++) {
                int val;    cin >> val; 
                y_up.push_back(val);
            }
        } else {
            for(int i=0; i<pot; i++) {
                int val;    cin >> val; 
                y_down.push_back(val);
            }
        }
    }
    // two points on same side and the remaining one on any of the other side 
    // generate all the possible areas of the triangle 
    int triangle_area = LLONG_MIN;

    triangle_area = max(triangle_area, height_b*determine_base(x_up));
    triangle_area = max(triangle_area, height_b*determine_base(x_down));
    triangle_area = max(triangle_area, height_a*determine_base(y_up));
    triangle_area = max(triangle_area, height_a*determine_base(y_down));

    cout << triangle_area << endl; 
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