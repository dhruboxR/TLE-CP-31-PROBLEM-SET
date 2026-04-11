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
    vector<int> shoe_size(length);
    map<int, int> size_freq;

    for(auto &data : shoe_size) {
        cin >> data;
        size_freq[ data ]++;
    }

    // if any of the shoe freq is 1 
    for(auto iterator : size_freq) {
        if(iterator.second == 1) {
            cout << -1 << endl;     return;
        }
    }

    // otherwise answer exists
    vector<int> permutation(length);
    for(int i=0; i<length; i++) {
        int temp = i;     // storing the first val
        while(i+1<length && shoe_size[i]==shoe_size[i+1]) {
            permutation[i] = i+1;   i++;    // currrent person gets the shoe of the nex person 
        }
        permutation[i] = temp;  // the last person gets the shoe of the first person 
    }

    for(auto data : permutation) cout << data+1 << " ";     // 1-based indexing 
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

/*     MEMORY LIMIT EXCEED :)

void solve() {
    int length;     cin >> length; 
    map<int, vector<int>> same_len;

    vector<int> shoe_size(length); 
    for(int i=0; i<length; i++) {
        int size;   cin >> size; 
        shoe_size.push_back(size); 

        same_len[size].push_back(i);    
    }

    // shuffle
    vector<int> shuffle_result;

    for(auto& [size, index_vect] : same_len) {
        int len = index_vect.size();
        if(len == 1) {
            cout << -1 << endl; 
            return;     // not possible 
        }

        reverse(index_vect.begin(), index_vect.end());

        if(len & 1) {
            swap(index_vect[len/2], index_vect[len/2 + 1]);
        }
        // store the results in the final vector
        for(int i=0; i<length; i++) {
            shuffle_result[index_vect[i]] = index_vect[i]+1;
        }
    } 
    for(auto data : shuffle_result) cout << data << " ";
    cout << endl; 
}

*/