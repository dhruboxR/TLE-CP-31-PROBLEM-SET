// LINK - https://codeforces.com/problemset/problem/1374/C
/*
You are given a bracket sequence s of length n, where n is even (divisible by two). 
The string s consists of n/2 opening brackets '(' and n/2 closing brackets ')'.

In one move, you can choose exactly one bracket and move it to the beginning of the string or to the end of the string 
(i.e. you choose some index i, remove the i-th character of s and insert it before or after all remaining characters of s).

Your task is to find the minimum number of moves required to obtain a regular bracket sequence from s. 
It can be proved that the answer always exists under the given constraints.

Recall what the regular bracket sequence is:

- "()" is a regular bracket sequence;
- if s is a regular bracket sequence then "(" + s + ")" is a regular bracket sequence;
- if s and t are regular bracket sequences then s + t is a regular bracket sequence.
  
For example, "()()", "(())()", "(())" and "()" are regular bracket sequences, 
but ")(", "()(" and ")))" are not.

You have to answer t independent test cases.

### Input
The first line of the input contains one integer t (1 ≤ t ≤ 2000) 
— the number of test cases. Then t test cases follow.

The first line of the test case contains one integer n (2 ≤ n ≤ 50) 
— the length of s. It is guaranteed that n is even. 
The second line of the test case contains the string s consisting of n/2 opening and n/2 closing brackets.

### Output
For each test case, print the answer — the minimum number of moves required to obtain a regular bracket sequence from s. 
It can be proved that the answer always exists under the given constraints.

### Example
#### Input

4
2
)(
4
()()
8
())()()(
10
)))((((())

#### Output

1
0
1
3

### Note
In the first test case of the example, it is sufficient to move the first bracket to the end of the string.

In the third test case of the example, it is sufficient to move the last bracket to the beginning of the string.

In the fourth test case of the example, we can choose the last three opening brackets, move them to the beginning of the string and obtain "((()))(())".
*/

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
    string bracket_sequence;    cin >> bracket_sequence;

    int count = length/2;
    while(bracket_sequence.find("()") != bracket_sequence.npos) {
        auto index = bracket_sequence.find("()");
        bracket_sequence.erase(index, 2);
        count--;
    }

    cout << count << endl;
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