/*
1869A - Make It Zero [ codeforces ] : 900 

Initially you are given an array a consisting or n >= 2 integers, and your job is to 
change the elements into zero. 
In one operation you can choose two indeces l and r (1<=l<=r<=n) and do the following : 
1. Bitwise XOR operation s = a'1 xor a'2 xor a'i 
2. Then, for all l <= i <= r , replace a'i with s which equals to 0 

You can use the operation above in any order at most 8 times 
It gurrenteed that the solution always exists.

INPUT 
The first line of input contains a single integer - the number of testcases. The description of testcases follows : 
The first line of the testcase contains a single integer n the length of array 
The second line of each testcase contains n integers a'1, a'2,....a'n the elements of array 

Output 
For each testcase in the fist line output a single integer k - the number of operations you use 
The print k lines 
in the i'th line print two integers which is the indices if l'i and r'i

You do not have to minimize solutions. If there are multiple solutions print any . 
Example
InputCopy
6
4
1 2 3 0
8
3 1 4 1 5 9 2 6
6
1 5 4 1 4 7
5
0 0 0 0 0
7
1 1 9 9 0 1 8
3
100 100 0

OutputCopy
1
1 4
2
4 7
1 8
6
1 2
3 4
5 6
1 3
4 6
1 6
0
4
1 2
6 7
3 4
6 7
1
1 2

Note
In the first test case, since 1 ⊕ 2 ⊕ 3 ⊕ 0 = 0, 
after performing the operation on segment [1,4],
all the elements in the array are equal to 0

In the second test case, after the first operation, the array becomes equal to [3,1,4,15,15,15,15,6], 
after the second operation, the array becomes equal to [0,0,0,0,0,0,0,0]
*/

#include <bits/stdc++.h>
#define int long long int  
using namespace std ; 

void solve() {

    int length;     cin >> length; 
    int integers[length] ; 

    for(auto &element : integers) {
        cin >> element ;
    }
    
    // if the length size is even then XOR of even elements will be 0 & we will need to perform 2 operations only 
    if( length%2 == 0) {
        cout << 2 << endl ; 
        cout << 1 << " " << length << endl ; 
        cout << 1 << " " << length << endl ; 
    } else {
        cout << 4 << endl ; 
        cout << 1 << " " << (length-1) << endl ; 
        cout << 1 << " " << (length-1) << endl ; 
        cout << (length-1) << " " << length << endl ; 
        cout << (length-1) << " " << length << endl ; 
    }
}

int32_t main() {
    ios_base::sync_with_stdio( false ) ; 
    cin.tie( NULL ) ;   

    int test_case;  cin >> test_case; 
    while( test_case-- ) {
        solve() ;
    }

    return 0 ;
}