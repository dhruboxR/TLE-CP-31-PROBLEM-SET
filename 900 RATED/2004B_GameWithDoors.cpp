// 2004B - GAMES WITH DOORS [ codeforces ] : 1000

/*
There are 100 rooms arranged in a row and 99 doors between them, the i'th door connects rooms i and i+1.
Each door can be either locked or unlocked. Initially all doors are unlocked.
We say that room x is reachable from room y is al doors between them are unlocked. 
You know that : 
- Alice is in some room from the segment [ l,r ] 
- Bob is in some room from the segment [ L,R ] 
- Alice & Bob are in different rooms. 

However you don't knwo the exact rooms they are in. 
You don't want Alice & Bob to reach each other, so you are going to lock some doors to prevent that. 
What's the minimum number of doors you should lock so that Alice and Bob cannot meet each other.
Regrdless their starting positions inside the given segments. 

INPUT 
The first line contains a single integer the number of testcases T. 

The first line of each test case contains two integer l and r - the bounds of the segment of rooms where Alice is located. 
The second line of each test case contains two integer L and R - the bounds of the segment of rooms where Bob is located. 

Example

InputCopy
4
1 2
3 4
2 5
2 5
3 7
6 7
4 5
2 8

OutputCopy
1
3
2
3

Note

In the first test case, it is sufficient to lock the door between rooms 2 and 3

In the second test case, the following doors have to be locked: (2,3), (3,4), (4,5)

In the third test case, the following doors have to be locked: (5,6) and (6,7)
*/

#include <bits/stdc++.h>
#define int long long int 
using namespace std ;

void solve() {
    int alice_start, alice_end;     cin >> alice_start >> alice_end ; 
    int bob_start, bob_end;         cin >> bob_start >> bob_end ; 

    // if bob's start is greater than alice's end point or bob's ending is less than alice's start 
    if(bob_start > alice_end || bob_end < alice_start) {
        // then all points are EXCLUSIVE [ NO MATCHES ] 
        cout << 1 << endl ;  
        return ; // and we will return from here 
    }

    // declare a vector for the rooms of alice and bob 
    vector<int> rooms(101, 0) ;         // initializing every element of the vector with 0 

    // ROOMS ALICE CAN VISIT 
    for(int i=alice_start; i<=alice_end; i++) {
        // increase the value of the room 
        rooms[i]++ ;
    } 
    // ROOMS BOB CAN VISIT 
    for(int j=bob_start; j<=bob_end; j++) {
        // increase the value of the room 
        rooms[j]++ ;
    }

    // now after marking the rooms for both the COOMMON ROOMS WILL HOLD THE VALUE:2 
    int doors_locked = 0 ;      // this is the answer 

    // iterate through the rooms 
    for(int k=1; k<101; k++) {
        
        // if the room holds 2 persons and the previous room holds 1 then we need to LOCK 
        if(rooms[k] == 2 && rooms[k-1] > 0) {
            doors_locked++ ;
        } 
        // if the room holds 1 person and the previous room holds 2 then we need to LOCK 
        if(rooms[k] == 1 && rooms[k-1] == 2) {
            doors_locked++ ;
        }
    }

    cout << doors_locked << endl ; 

}

int32_t main() {

    ios_base::sync_with_stdio(false) ; 
    cin.tie( NULL ) ; 

    int test_Case;  cin >> test_Case; 

    while(test_Case--) {
        solve() ; 
    } 

    return 0 ; 
}